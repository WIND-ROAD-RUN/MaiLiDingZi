#pragma once

#include<QObject>
#include "ImageProcessorModule.hpp"
#include "imgPro_ImageProcess.hpp"
#include"IModule.hpp"

void findHolesInMask(
	std::vector<rw::DetectionRectangleInfo>& hollowRects,
	const std::pair<int, int>& roiOffset,
	int ignoreBorderX = 0,
	int ignoreBorderY = 0,
	const rw::DetectionRectangleInfo& bodyInfo = {}
);

std::vector<rw::DetectionRectangleInfo> filterProWithShieldWithoutBody(
	const std::vector<rw::DetectionRectangleInfo>& hollowRects,
	const std::vector<rw::DetectionRectangleInfo>& shields
);

int countProsArea(const std::vector<rw::DetectionRectangleInfo>& pros);

class ImgProModule
	:public QObject, public IModule<bool>
{
	Q_OBJECT
private:
	static constexpr int  imgProSignalWorkThreadNum = 1;
public:
	bool build() override;
	void destroy() override;
	void start() override;
	void stop() override;
private:
	void buildImgProContext();
	void buildImgProContextPreProcess();

	void resetImgProIsUpdate(bool state);
public:
	rw::imgPro::ImageProcessContext imageProcessContext_PreProcess;

	std::atomic<bool> imgProIsUpdate[4];
private:
	void buildImageProcessingModule(size_t num);
	void destroyImageProcessingModule();

	void buildImageProcessingPreModule(size_t num);
public:
	std::unique_ptr<ImageProcessingModule> imageProcessingModule1{ nullptr };
	std::unique_ptr<ImageProcessingModule> imageProcessingModule2{ nullptr };

public slots:
	void onUpdateImgProContext();
};