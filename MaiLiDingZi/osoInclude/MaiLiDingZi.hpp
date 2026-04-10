#pragma once

#include"oso_core.h"
#include <string>

namespace cdm {
    class MaiLiDingZiConfig
    {
    public:
        MaiLiDingZiConfig() = default;
        ~MaiLiDingZiConfig() = default;

        MaiLiDingZiConfig(const rw::oso::ObjectStoreAssembly& assembly);
        MaiLiDingZiConfig(const MaiLiDingZiConfig& obj);

        MaiLiDingZiConfig& operator=(const MaiLiDingZiConfig& obj);
        operator rw::oso::ObjectStoreAssembly() const;
        bool operator==(const MaiLiDingZiConfig& obj) const;
        bool operator!=(const MaiLiDingZiConfig& obj) const;

    public:
        int totalProductionVolume{ 0 };
        int totalDefectiveVolume{ 0 };
        bool isDebug{ false };
        bool isDefect{ false };
        bool isshibiekuang{ true };
        bool iswenzi{ true };
    };

    inline MaiLiDingZiConfig::MaiLiDingZiConfig(const rw::oso::ObjectStoreAssembly& assembly)
    {
        auto isAccountAssembly = assembly.getName();
        if (isAccountAssembly != "$class$MaiLiDingZiConfig$")
        {
            throw std::runtime_error("Assembly is not $class$MaiLiDingZiConfig$");
        }
        auto totalProductionVolumeItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$totalProductionVolume$"));
        if (!totalProductionVolumeItem) {
            throw std::runtime_error("$variable$totalProductionVolume is not found");
        }
        totalProductionVolume = totalProductionVolumeItem->getValueAsInt();
        auto totalDefectiveVolumeItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$totalDefectiveVolume$"));
        if (!totalDefectiveVolumeItem) {
            throw std::runtime_error("$variable$totalDefectiveVolume is not found");
        }
        totalDefectiveVolume = totalDefectiveVolumeItem->getValueAsInt();
        auto isDebugItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isDebug$"));
        if (!isDebugItem) {
            throw std::runtime_error("$variable$isDebug is not found");
        }
        isDebug = isDebugItem->getValueAsBool();
        auto isDefectItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isDefect$"));
        if (!isDefectItem) {
            throw std::runtime_error("$variable$isDefect is not found");
        }
        isDefect = isDefectItem->getValueAsBool();
        auto isshibiekuangItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isshibiekuang$"));
        if (!isshibiekuangItem) {
            throw std::runtime_error("$variable$isshibiekuang is not found");
        }
        isshibiekuang = isshibiekuangItem->getValueAsBool();
        auto iswenziItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$iswenzi$"));
        if (!iswenziItem) {
            throw std::runtime_error("$variable$iswenzi is not found");
        }
        iswenzi = iswenziItem->getValueAsBool();
    }

    inline MaiLiDingZiConfig::MaiLiDingZiConfig(const MaiLiDingZiConfig& obj)
    {
        totalProductionVolume = obj.totalProductionVolume;
        totalDefectiveVolume = obj.totalDefectiveVolume;
        isDebug = obj.isDebug;
        isDefect = obj.isDefect;
        isshibiekuang = obj.isshibiekuang;
        iswenzi = obj.iswenzi;
    }

    inline MaiLiDingZiConfig& MaiLiDingZiConfig::operator=(const MaiLiDingZiConfig& obj)
    {
        if (this != &obj) {
            totalProductionVolume = obj.totalProductionVolume;
            totalDefectiveVolume = obj.totalDefectiveVolume;
            isDebug = obj.isDebug;
            isDefect = obj.isDefect;
            isshibiekuang = obj.isshibiekuang;
            iswenzi = obj.iswenzi;
        }
        return *this;
    }

    inline MaiLiDingZiConfig::operator rw::oso::ObjectStoreAssembly() const
    {
        rw::oso::ObjectStoreAssembly assembly;
        assembly.setName("$class$MaiLiDingZiConfig$");
        auto totalProductionVolumeItem = std::make_shared<rw::oso::ObjectStoreItem>();
        totalProductionVolumeItem->setName("$variable$totalProductionVolume$");
        totalProductionVolumeItem->setValueFromInt(totalProductionVolume);
        assembly.addItem(totalProductionVolumeItem);
        auto totalDefectiveVolumeItem = std::make_shared<rw::oso::ObjectStoreItem>();
        totalDefectiveVolumeItem->setName("$variable$totalDefectiveVolume$");
        totalDefectiveVolumeItem->setValueFromInt(totalDefectiveVolume);
        assembly.addItem(totalDefectiveVolumeItem);
        auto isDebugItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isDebugItem->setName("$variable$isDebug$");
        isDebugItem->setValueFromBool(isDebug);
        assembly.addItem(isDebugItem);
        auto isDefectItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isDefectItem->setName("$variable$isDefect$");
        isDefectItem->setValueFromBool(isDefect);
        assembly.addItem(isDefectItem);
        auto isshibiekuangItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isshibiekuangItem->setName("$variable$isshibiekuang$");
        isshibiekuangItem->setValueFromBool(isshibiekuang);
        assembly.addItem(isshibiekuangItem);
        auto iswenziItem = std::make_shared<rw::oso::ObjectStoreItem>();
        iswenziItem->setName("$variable$iswenzi$");
        iswenziItem->setValueFromBool(iswenzi);
        assembly.addItem(iswenziItem);
        return assembly;
    }

    inline bool MaiLiDingZiConfig::operator==(const MaiLiDingZiConfig& obj) const
    {
        return totalProductionVolume == obj.totalProductionVolume && totalDefectiveVolume == obj.totalDefectiveVolume && isDebug == obj.isDebug && isDefect == obj.isDefect && isshibiekuang == obj.isshibiekuang && iswenzi == obj.iswenzi;
    }

    inline bool MaiLiDingZiConfig::operator!=(const MaiLiDingZiConfig& obj) const
    {
        return !(*this == obj);
    }

}

