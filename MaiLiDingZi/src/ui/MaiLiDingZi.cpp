#include "MaiLiDingZi.h"

#include <QDir>
#include <QMessageBox>
#include <QProcess>

#include "ui_MaiLiDingZi.h"
#include <QPushButton>

#include "DlgProductSet.h"
#include "Modules.hpp"
#include "NumberKeyboard.h"
#include "rqw_RunEnvCheck.hpp"
#include "Utilty.hpp"


MaiLiDingZi::MaiLiDingZi(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MaiLiDingZiClass())
{
	ui->setupUi(this);

	initializeComponents();
}

MaiLiDingZi::~MaiLiDingZi()
{
	Modules::getInstance().stop();
	Modules::getInstance().destroy();
	delete ui;
}

#ifdef BUILD_WITHOUT_HARDWARE
void MaiLiDingZi::cBox_testPushImg_checked(bool checked)
{
	if (checked)
	{
		Modules::getInstance().test_module.testImgPush = true;
	}
	else
	{
		Modules::getInstance().test_module.testImgPush = false;
	}
}
#endif

void MaiLiDingZi::build_ui()
{
	build_MaiLiDingZiData();
	build_DlgCloseForm();

#ifdef BUILD_WITHOUT_HARDWARE
	cBox_testPushImg = new QCheckBox(this);
	cBox_testPushImg->setText("图像推送状态");
	ui->gBox_infor->layout()->addWidget(cBox_testPushImg);
	QObject::connect(cBox_testPushImg, &QCheckBox::clicked,
		this, &MaiLiDingZi::cBox_testPushImg_checked);
#endif
}

void MaiLiDingZi::build_connect()
{
	QObject::connect(ui->pbtn_exit, &QPushButton::clicked,
		this, &MaiLiDingZi::pbtn_exit_clicked);
	QObject::connect(ui->pbtn_set, &QPushButton::clicked,
		this, &MaiLiDingZi::pbtn_set_clicked);
	QObject::connect(ui->rbtn_debug, &QRadioButton::clicked,
		this, &MaiLiDingZi::rbtn_debug_checked);
	QObject::connect(ui->rbtn_removeFunc, &QRadioButton::clicked,
		this, &MaiLiDingZi::rbtn_removeFunc_checked);
	QObject::connect(ui->ckb_shibiekuang, &QCheckBox::clicked,
		this, &MaiLiDingZi::ckb_shibiekuang_checked);
	QObject::connect(ui->ckb_wenzi, &QCheckBox::clicked,
		this, &MaiLiDingZi::ckb_wenzi_checked);
	QObject::connect(ui->pbtn_resetProduct, &QPushButton::clicked,
		this, &MaiLiDingZi::pbtn_resetProduct_clicked);
	// 连接显示标题
	QObject::connect(clickableTitle, &rw::rqw::ClickableLabel::clicked,
		this, &MaiLiDingZi::lb_title_clicked);
}

void MaiLiDingZi::build_MaiLiDingZiData()
{
	auto& qiXinShiJinDanXiangJiConfig = Modules::getInstance().configManagerModule.maiLiDingZiConfig;
	auto& setConfig = Modules::getInstance().configManagerModule.setConfig;
	qiXinShiJinDanXiangJiConfig.isDebug = false;
	qiXinShiJinDanXiangJiConfig.isDefect = true;		// 默认开启剔废
	qiXinShiJinDanXiangJiConfig.isshibiekuang = true;
	qiXinShiJinDanXiangJiConfig.iswenzi = false;

	ui->label_produceTotalValue->setText(QString::number(qiXinShiJinDanXiangJiConfig.totalProductionVolume));
	ui->label_wasteProductsValue->setText(QString::number(qiXinShiJinDanXiangJiConfig.totalDefectiveVolume));
	ui->rbtn_removeFunc->setChecked(qiXinShiJinDanXiangJiConfig.isDefect);
	
	ui->ckb_shibiekuang->setChecked(qiXinShiJinDanXiangJiConfig.isshibiekuang);
	ui->ckb_wenzi->setChecked(qiXinShiJinDanXiangJiConfig.iswenzi);

	rbtn_removeFunc_checked(true);

	ini_clickableTitle();
	changeLanguage(setConfig.changeLanguageIndex);
}

void MaiLiDingZi::ini_clickableTitle()
{
	// 初始化标题label
	clickableTitle = new rw::rqw::ClickableLabel(this);
	auto layoutTitle = ui->groupBox_head->layout();
	layoutTitle->replaceWidget(ui->label_title, clickableTitle);
	delete ui->label_title;
	clickableTitle->setText("湿巾检测");
	clickableTitle->setStyleSheet("QLabel {font-size: 30px;font-weight: bold;color: rgb(255, 255, 255);padding: 5px 5px;border-bottom: 2px solid #cccccc;}");
}

void MaiLiDingZi::build_DlgCloseForm()
{
	_dlgCloseForm = new DlgCloseForm(this);
}

void MaiLiDingZi::initializeComponents()
{
	build_ui();

	build_camera();

	build_zmotion();

	build_connect();

#ifndef BUILD_WITHOUT_HARDWARE
#endif
}

void MaiLiDingZi::build_camera()
{
	auto& cameraModules = Modules::getInstance().cameraModule;
	auto errors = cameraModules.getBuildResults();
	updateCameraLabelState(1, true);
	updateCameraLabelState(2, true);
	updateCameraLabelState(3, true);

	for (const auto& error : errors)
	{
		auto index = static_cast<int>(error);
		updateCameraLabelState(index, false);
	}
}

void MaiLiDingZi::build_zmotion()
{
	auto& motionControllerModule = Modules::getInstance().motionControllerModule;
	auto isBuildZmotion = motionControllerModule.zmotion->connect();
	updateCameraLabelState(0, isBuildZmotion);
}

void MaiLiDingZi::changeLanguage(int index)
{
	// 中文
	if (0 == index)
	{
		clickableTitle->setText("钉子检测");
		ui->label_cameraStateTitle->setText("相机状态");
		ui->label_info->setText("统计信息");
		ui->pbtn_resetProduct->setText("产量清零");
		ui->label_produceTotal->setText("生产总量");
		ui->label_wasteProducts->setText("废品总量");
		ui->rbtn_debug->setText("调试模式");
		ui->ckb_shibiekuang->setText("识别框");
		ui->ckb_wenzi->setText("文字");
		ui->rbtn_removeFunc->setText("剔除功能");
		ui->pbtn_set->setText("设置");

		// UI 里有但原代码没覆盖：底部提示/报警信息
		ui->label_companyInfo->setText("暂无报警信息");
	}
	// 英文
	else if (1 == index)
	{
		// 标题：建议用更自然的英文 & 保持一行/两行皆可
		clickableTitle->setText("Nail Inspection");

		// 标题区
		ui->label_cameraStateTitle->setText("Camera Status");

		// 统计区
		ui->label_info->setText("Statistics");
		ui->pbtn_resetProduct->setText("Clear Count");
		ui->label_produceTotal->setText("Total Output");
		ui->label_wasteProducts->setText("Total Rejects");

		// 模式/功能
		ui->rbtn_debug->setText("Debug Mode");
		ui->ckb_shibiekuang->setText("Box");
		ui->ckb_wenzi->setText("Text");
		ui->rbtn_removeFunc->setText("Reject Enable");

		// 操作按钮
		ui->pbtn_set->setText("Settings");

		// UI 里有但原代码没覆盖：底部提示/报警信息
		ui->label_companyInfo->setText("No alarms");
	}
}

void MaiLiDingZi::updateCameraLabelState(int cameraIndex, bool state)
{
	auto& setConfig = Modules::getInstance().configManagerModule.setConfig;
	switch (cameraIndex)
	{
	case 1:
		if (state) {
			if (0 == setConfig.changeLanguageIndex)
			{
				ui->label_camera1State->setText("连接成功");
			}
			else if (1 == setConfig.changeLanguageIndex)
			{
				ui->label_camera1State->setText("Connected");
			}
			ui->label_camera1State->setStyleSheet(QString("QLabel{color:rgb(0, 230, 0);font-size: 18px;font - weight: bold;padding: 5px 5px;} "));
		}
		else {
			if (0 == setConfig.changeLanguageIndex)
			{
				ui->label_camera1State->setText("连接失败");
			}
			else if (1 == setConfig.changeLanguageIndex)
			{
				ui->label_camera1State->setText("Disconnected");
			}
			ui->label_camera1State->setStyleSheet(QString("QLabel{color:rgb(230, 0, 0);font-size: 18px;font - weight: bold;padding: 5px 5px;} "));
		}
		break;
	case 2:
		if (state) {
			if (0 == setConfig.changeLanguageIndex)
			{
				ui->label_camera2State->setText("连接成功");
			}
			else if (1 == setConfig.changeLanguageIndex)
			{
				ui->label_camera2State->setText("Connected");
			}
			ui->label_camera2State->setStyleSheet(QString("QLabel{color:rgb(0, 230, 0);font-size: 18px;font - weight: bold;padding: 5px 5px;} "));
		}
		else {
			if (0 == setConfig.changeLanguageIndex)
			{
				ui->label_camera2State->setText("连接失败");
			}
			else if (1 == setConfig.changeLanguageIndex)
			{
				ui->label_camera2State->setText("Disconnected");
			}
			ui->label_camera2State->setStyleSheet(QString("QLabel{color:rgb(230, 0, 0);font-size: 18px;font - weight: bold;padding: 5px 5px;} "));
		}
		break;
	default:
		break;
	}
}

void MaiLiDingZi::onUpdateStatisticalInfoUI()
{
	auto& statisticalInfo = Modules::getInstance().runtimeInfoModule.statisticalInfo;
	ui->label_produceTotalValue->setText(QString::number(statisticalInfo.produceCount.load()));
	ui->label_wasteProductsValue->setText(QString::number(statisticalInfo.wasteCount.load()));
}

void MaiLiDingZi::onCameraDisplay(size_t index, QPixmap image)
{
	if (1 == index)
	{
		ui->label_imgDisplay_1->setPixmap(image.scaled(ui->label_imgDisplay_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}
	else if (2 == index)
	{
		ui->label_imgDisplay_2->setPixmap(image.scaled(ui->label_imgDisplay_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}
}

void MaiLiDingZi::lb_title_clicked()
{
	if (0 != minimizeCount)
	{
		minimizeCount--;
	}
	else if (0 >= minimizeCount)
	{
		// 最小化主窗体
		this->showMinimized();
		minimizeCount = 3; // 重置最小化计数器
	}

}

void MaiLiDingZi::pbtn_exit_clicked()
{
#ifdef NDEBUG
	if (_dlgCloseForm)
	{
		_dlgCloseForm->exec();
	}
#else
	this->close();
#endif
}

void MaiLiDingZi::pbtn_set_clicked()
{
	auto& _dlgProductSet = Modules::getInstance().uiModule._dlgProductSet;
	_dlgProductSet->setFixedSize(this->width(), this->height());
	_dlgProductSet->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
	_dlgProductSet->exec();
}

void MaiLiDingZi::rbtn_debug_checked(bool checked)
{
	auto isRuning = ui->rbtn_removeFunc->isChecked();

	auto& runningState = Modules::getInstance().runtimeInfoModule.runningState;
	auto& camera1 = Modules::getInstance().cameraModule.camera1;
	if (!isRuning) {
		if (checked) {
			runningState = RunningState::Debug;
			if (camera1)
			{
				camera1->setTriggerState(false);
				camera1->setFrameRate(5);
			}
		}
		else {
			runningState = RunningState::Stop;
		}
		ui->ckb_shibiekuang->setVisible(checked);
		ui->ckb_wenzi->setVisible(checked);
	}
	else {
		ui->rbtn_debug->setChecked(false);
	}
}

void MaiLiDingZi::rbtn_removeFunc_checked(bool checked)
{
	auto& runningState = Modules::getInstance().runtimeInfoModule.runningState;
	auto& camera1 = Modules::getInstance().cameraModule.camera1;
	if (checked)
	{
		runningState = RunningState::OpenRemoveFunc;
		if (camera1)
		{
			camera1->setTriggerState(true);
			camera1->setTriggerSource(rw::rqw::TriggerSource::Line0);
			camera1->setFrameRate(50);
		}
		ui->rbtn_debug->setChecked(false);
		ui->ckb_shibiekuang->setVisible(false);
		ui->ckb_wenzi->setVisible(false);
	}
	else
	{
		runningState = RunningState::Stop;
	}
}

void MaiLiDingZi::ckb_shibiekuang_checked(bool checked)
{
	auto& qiXinShiJinDanXiangJiConfig = Modules::getInstance().configManagerModule.maiLiDingZiConfig;
	qiXinShiJinDanXiangJiConfig.isshibiekuang = ui->ckb_shibiekuang->isChecked();

	emit shibiekuangChanged();
}

void MaiLiDingZi::ckb_wenzi_checked(bool checked)
{
	auto& qiXinShiJinDanXiangJiConfig = Modules::getInstance().configManagerModule.maiLiDingZiConfig;
	qiXinShiJinDanXiangJiConfig.iswenzi = ui->ckb_wenzi->isChecked();

	emit wenziChanged();
}

void MaiLiDingZi::pbtn_resetProduct_clicked()
{
	auto& qiXinShiJinDanXiangJiConfig = Modules::getInstance().configManagerModule.maiLiDingZiConfig;

	qiXinShiJinDanXiangJiConfig.totalProductionVolume = 0;
	qiXinShiJinDanXiangJiConfig.totalDefectiveVolume = 0;

	onUpdateStatisticalInfoUI();
}