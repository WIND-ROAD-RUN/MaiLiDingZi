#include "osoFIleUtiltyFunc.hpp"

#include "Utilty.hpp"

rw::imgPro::EliminationInfoFunc::ClassIdWithConfigMap cdm::ScoreConfigConvert::toClassIdWithEliConfigMap(
	const cdm::ScoreConfig& config, double areaFactor, double scoreFactor)
{
	rw::imgPro::EliminationInfoFunc::ClassIdWithConfigMap result{};

	rw::imgPro::EliminationInfoGetConfig configBase;
	configBase.isUsingArea = true;
	configBase.isUsingScore = true;
	configBase.areaFactor = areaFactor;
	configBase.scoreFactor = scoreFactor;
	configBase.areaIsUsingComplementarySet = false;
	configBase.scoreIsUsingComplementarySet = false;

	for (int i = ClassId::minNum; i <= ClassId::maxNum; i++)
	{
		result[i] = configBase;
	}

	// body不参与剔废
	result[ClassId::dingZi].isUsingArea = false;
	result[ClassId::dingZi].isUsingScore = true;

	return result;
}

rw::imgPro::DefectResultInfoFunc::ClassIdWithConfigMap cdm::ScoreConfigConvert::toClassIdWithDefConfigMap(
	const cdm::ScoreConfig& config)
{
	rw::imgPro::DefectResultInfoFunc::ClassIdWithConfigMap result;
	rw::imgPro::DefectResultInfoFunc::Config configBase;
	configBase.isEnable = false;
	for (int i = ClassId::minNum; i <= ClassId::maxNum; i++)
	{
		result[i] = configBase;
	}

	// body不参与剔废
	result[ClassId::dingZi].isEnable = true;

	return result;
}
