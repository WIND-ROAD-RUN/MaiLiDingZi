#include "Utilty.hpp"

QString Utility::cameraIp1 = "1";
QString Utility::cameraIp2 = "2";
QString Utility::zmotionIp = "192.168.0.11";

std::unordered_map<rw::imgPro::ClassId, rw::imgPro::ClassIdName> ClassId::classIdNameMap = {
	{ClassId::zangWu,"脏污"},
	{ClassId::xiaoZangWu,"小脏污"},
	{ClassId::jieTou,"接头"},
	{ClassId::body,"本体"},
	{ClassId::huaPo,"划破"},
	{ClassId::siLie,"撕裂"},
	{ClassId::queShi,"缺失"},
	{ClassId::weiZhiQueXian,"未知缺陷"},
	{ClassId::weiZhiQueXianTotal,"总未知缺陷"}
};

std::vector<rw::imgPro::ClassId> ClassId::classids = {
	ClassId::zangWu,
	ClassId::xiaoZangWu,
	ClassId::jieTou,
	ClassId::body,
	ClassId::huaPo,
	ClassId::siLie,
	ClassId::queShi,
	ClassId::weiZhiQueXian,
	ClassId::weiZhiQueXianTotal
};