#pragma once

#include <QCheckBox>
#include <QObject>
#include "IModule.hpp"

class MaiLiDingZi;
class DlgProductSet;
class DlgProductScore;

class UIModule
	: public QObject, public IModule<void>
{
	Q_OBJECT
public:
	void build() override;
	void destroy() override;
	void start() override;
	void stop() override;
public:
	void ini_dlgProductScoreGroupList();
	void ini_dlgProductSetCheckList();
	void connectSetAndScore();
public:
	DlgProductSet* _dlgProductSet = nullptr;
	MaiLiDingZi* _qiXinShiJinShuangXiangJi = nullptr;
	DlgProductScore* _dlgProductScore = nullptr;

	QVector<QCheckBox*> _dlgProductSetCheckList{};
	QVector<QWidget*> _dlgProductScoreGroupList{};
};
