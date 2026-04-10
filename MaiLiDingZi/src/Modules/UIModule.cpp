#include "UIModule.hpp"
#include "DlgProductSet.h"
#include "DlgProductScore.h"
#include "MaiLiDingZi.h"
#include "ui_DlgProductScore.h"
#include "ui_DlgProductSet.h"

void UIModule::build()
{
	_dlgProductSet = new DlgProductSet();
	_dlgProductScore = new DlgProductScore();

	// 构建分数界面与设置界面的UI联动
	ini_dlgProductScoreGroupList();
	ini_dlgProductSetCheckList();
	connectSetAndScore();
}

void UIModule::destroy()
{
	if (_dlgProductSet)
	{
		delete _dlgProductSet;
		_dlgProductSet = nullptr;
	}
	if (_dlgProductScore)
	{
		delete _dlgProductScore;
		_dlgProductScore = nullptr;
	}
}

void UIModule::start()
{
}

void UIModule::stop()
{
}

void UIModule::ini_dlgProductScoreGroupList()
{
	_dlgProductScoreGroupList = {
		_dlgProductScore->ui->widget_zangwu,
		_dlgProductScore->ui->widget_xiaozangwu,
		_dlgProductScore->ui->widget_jietou,
		_dlgProductScore->ui->widget_body,
		_dlgProductScore->ui->widget_huapo,
		_dlgProductScore->ui->widget_weizhiquexian,
		_dlgProductScore->ui->widget_silie,
		_dlgProductScore->ui->widget_queshi
	};
}

void UIModule::ini_dlgProductSetCheckList()
{
	_dlgProductSetCheckList = {
		_dlgProductSet->ui->ckb_zangwu,
		_dlgProductSet->ui->ckb_xiaozangwu,
		_dlgProductSet->ui->ckb_jietou,
		_dlgProductSet->ui->ckb_body,
		_dlgProductSet->ui->ckb_huapo,
		_dlgProductSet->ui->ckb_weizhiquexian,
		_dlgProductSet->ui->ckb_silie,
		_dlgProductSet->ui->ckb_queshi
	};
}

void UIModule::connectSetAndScore()
{
	for (int i = 0; i < _dlgProductSetCheckList.size(); ++i) {
		connect(_dlgProductSetCheckList[i], &QCheckBox::toggled, _dlgProductScoreGroupList[i], &QWidget::setVisible);
		_dlgProductScoreGroupList[i]->setVisible(_dlgProductSetCheckList[i]->isChecked());
	}
}
