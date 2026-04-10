#pragma once

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class DlgProductSetClass; };
QT_END_NAMESPACE

class DlgProductSet : public QDialog
{
	Q_OBJECT

public:
	DlgProductSet(QWidget* parent = nullptr);
	~DlgProductSet();

public:
	void build_ui();
	void read_config();
	void build_connect();

signals:
	void paramsChanged();

	void emit_changeLanguage(int index);
public slots:
	void changeLanguage(int index);
private slots:
	void btn_close_clicked();

	void btn_jishuguangdianyanshi_clicked();
	void btn_paizhaoyanshi_clicked();
	void btn_cipinguangdianjiange_clicked();
	void btn_fenliaojishu_clicked();
	void btn_xiangjiguangdianpingbishijian_clicked();
	void btn_defectIgnoreX_clicked();
	void btn_defectIgnoreY_clicked();
	void btn_tifeijiange1_clicked();
	void btn_tifeijiange2_clicked();

	void btn_testTrigger1_1_clicked();
	void btn_testTrigger2_1_clicked();
	void btn_testTrigger1_2_clicked();
	void btn_testTrigger2_2_clicked();

	void btn_shangxianwei1_clicked();
	void btn_xiaxianwei1_clicked();
	void btn_baoguang1_clicked();
	void btn_zengyi1_clicked();
	void btn_xiangsudangliang1_clicked();
	void btn_shangxianwei2_clicked();
	void btn_xiaxianwei2_clicked();
	void btn_baoguang2_clicked();
	void btn_zengyi2_clicked();
	void btn_xiangsudangliang2_clicked();

	void ckb_zangwu_checked(bool isChecked);
	void ckb_xiaozangwu_checked(bool isChecked);
	void ckb_jietou_checked(bool isChecked);
	void ckb_body_checked(bool isChecked);
	void ckb_huapo_checked(bool isChecked);
	void ckb_silie_checked(bool isChecked);
	void ckb_queshi_checked(bool isChecked);
	void ckb_weizhiquexian_checked(bool isChecked);

public:
	Ui::DlgProductSetClass* ui;
};

