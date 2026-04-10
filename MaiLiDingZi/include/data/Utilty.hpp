#pragma once
#include <QString>

#include "imgPro_ImageProcessUtilty.hpp"

inline struct GlobalPath
{
public:
	QString projectHome = R"(D:\zfkjData\QiXinShiJinShuangXiangJi\)";
public:
	QString configRootPath = projectHome + R"(config\)";
	QString modelRootPath = projectHome + R"(model\)";
	QString qiXinShiJinShuangXiangJiConfigPath = configRootPath + R"(QiXinShiJinShuangXiangJiConfig.xml)";
	QString setConfigPath = configRootPath + R"(SetConfig.xml)";
	QString scoreConfigPath = configRootPath + R"(ScoreConfig.xml)";
	QString modelPath = modelRootPath + R"(QiXinShiJinWetPapers.engine)";
public:
	QString imageSaveRootPath = R"(D:\Images\)";
public:
	QString testImgDirPath = R"(D:\ImgStorage\WetPapers)";
}globalPath;

struct ClassId
{
public:
	static constexpr int minNum = 0;
	static constexpr int zangWu = 0;
	static constexpr int xiaoZangWu = 1;
	static constexpr int jieTou = 2;
	static constexpr int body = 3;
	static constexpr int huaPo = 4;
	static constexpr int siLie = 5;
	static constexpr int queShi = 6;

	static constexpr int customClassIdMin = 6;

	static constexpr int weiZhiQueXian = 7;
	static constexpr int weiZhiQueXianTotal = 8;

	static constexpr int maxNum = 8;
	static constexpr int indexCount = 9;
	static std::unordered_map<rw::imgPro::ClassId, rw::imgPro::ClassIdName> classIdNameMap;
	static std::vector<rw::imgPro::ClassId> classids;
};

struct Utility
{
	static QString cameraIp1;
	static QString cameraIp2;
	static QString zmotionIp;
};

// 图片信息
struct MatInfo {
	cv::Mat image;	// 图片内容
	float location;	// 记录拍照瞬间的时间点
	size_t index;	// 拍照的相机的下标
};

