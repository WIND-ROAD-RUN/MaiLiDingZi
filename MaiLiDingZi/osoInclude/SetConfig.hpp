#pragma once

#include"oso_core.h"
#include <string>

namespace cdm {
    class SetConfig
    {
    public:
        SetConfig() = default;
        ~SetConfig() = default;

        SetConfig(const rw::oso::ObjectStoreAssembly& assembly);
        SetConfig(const SetConfig& obj);

        SetConfig& operator=(const SetConfig& obj);
        operator rw::oso::ObjectStoreAssembly() const;
        bool operator==(const SetConfig& obj) const;
        bool operator!=(const SetConfig& obj) const;

    public:
        double jishuguangdianyanshi{ 0 };
        double paizhaoyanshi{ 0 };
        int cipinguangdianjiange{ 0 };
        double fenliaojishu{ 0 };
        double xiangjiguangdianpingbishijian{ 0 };
        double defectIgnoreX{ 0 };
        double defectIgnoreY{ 0 };
        int tifeijiange1{ 0 };
        int tifeijiange2{ 0 };
        double shangxianwei1{ 0 };
        double xiaxianwei1{ 0 };
        double baoguang1{ 0 };
        double zengyi1{ 0 };
        double xiangsudangliang1{ 0 };
        double shangxianwei2{ 0 };
        double xiaxianwei2{ 0 };
        double baoguang2{ 0 };
        double zengyi2{ 0 };
        double xiangsudangliang2{ 0 };
        bool isZangWu{ false };
        bool isXiaoZangWu{ false };
        bool isJieTou{ false };
        bool isBody{ false };
        bool isHuaPo{ false };
        bool isSiLie{ false };
        bool isQueShi{ false };
        bool isWeiZhiQueXian{ false };
        int changeLanguageIndex{ 0 };
    };

    inline SetConfig::SetConfig(const rw::oso::ObjectStoreAssembly& assembly)
    {
        auto isAccountAssembly = assembly.getName();
        if (isAccountAssembly != "$class$SetConfig$")
        {
            throw std::runtime_error("Assembly is not $class$SetConfig$");
        }
        auto jishuguangdianyanshiItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$jishuguangdianyanshi$"));
        if (!jishuguangdianyanshiItem) {
            throw std::runtime_error("$variable$jishuguangdianyanshi is not found");
        }
        jishuguangdianyanshi = jishuguangdianyanshiItem->getValueAsDouble();
        auto paizhaoyanshiItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$paizhaoyanshi$"));
        if (!paizhaoyanshiItem) {
            throw std::runtime_error("$variable$paizhaoyanshi is not found");
        }
        paizhaoyanshi = paizhaoyanshiItem->getValueAsDouble();
        auto cipinguangdianjiangeItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$cipinguangdianjiange$"));
        if (!cipinguangdianjiangeItem) {
            throw std::runtime_error("$variable$cipinguangdianjiange is not found");
        }
        cipinguangdianjiange = cipinguangdianjiangeItem->getValueAsInt();
        auto fenliaojishuItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$fenliaojishu$"));
        if (!fenliaojishuItem) {
            throw std::runtime_error("$variable$fenliaojishu is not found");
        }
        fenliaojishu = fenliaojishuItem->getValueAsDouble();
        auto xiangjiguangdianpingbishijianItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$xiangjiguangdianpingbishijian$"));
        if (!xiangjiguangdianpingbishijianItem) {
            throw std::runtime_error("$variable$xiangjiguangdianpingbishijian is not found");
        }
        xiangjiguangdianpingbishijian = xiangjiguangdianpingbishijianItem->getValueAsDouble();
        auto defectIgnoreXItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$defectIgnoreX$"));
        if (!defectIgnoreXItem) {
            throw std::runtime_error("$variable$defectIgnoreX is not found");
        }
        defectIgnoreX = defectIgnoreXItem->getValueAsDouble();
        auto defectIgnoreYItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$defectIgnoreY$"));
        if (!defectIgnoreYItem) {
            throw std::runtime_error("$variable$defectIgnoreY is not found");
        }
        defectIgnoreY = defectIgnoreYItem->getValueAsDouble();
        auto tifeijiange1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$tifeijiange1$"));
        if (!tifeijiange1Item) {
            throw std::runtime_error("$variable$tifeijiange1 is not found");
        }
        tifeijiange1 = tifeijiange1Item->getValueAsInt();
        auto tifeijiange2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$tifeijiange2$"));
        if (!tifeijiange2Item) {
            throw std::runtime_error("$variable$tifeijiange2 is not found");
        }
        tifeijiange2 = tifeijiange2Item->getValueAsInt();
        auto shangxianwei1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$shangxianwei1$"));
        if (!shangxianwei1Item) {
            throw std::runtime_error("$variable$shangxianwei1 is not found");
        }
        shangxianwei1 = shangxianwei1Item->getValueAsDouble();
        auto xiaxianwei1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$xiaxianwei1$"));
        if (!xiaxianwei1Item) {
            throw std::runtime_error("$variable$xiaxianwei1 is not found");
        }
        xiaxianwei1 = xiaxianwei1Item->getValueAsDouble();
        auto baoguang1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$baoguang1$"));
        if (!baoguang1Item) {
            throw std::runtime_error("$variable$baoguang1 is not found");
        }
        baoguang1 = baoguang1Item->getValueAsDouble();
        auto zengyi1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$zengyi1$"));
        if (!zengyi1Item) {
            throw std::runtime_error("$variable$zengyi1 is not found");
        }
        zengyi1 = zengyi1Item->getValueAsDouble();
        auto xiangsudangliang1Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$xiangsudangliang1$"));
        if (!xiangsudangliang1Item) {
            throw std::runtime_error("$variable$xiangsudangliang1 is not found");
        }
        xiangsudangliang1 = xiangsudangliang1Item->getValueAsDouble();
        auto shangxianwei2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$shangxianwei2$"));
        if (!shangxianwei2Item) {
            throw std::runtime_error("$variable$shangxianwei2 is not found");
        }
        shangxianwei2 = shangxianwei2Item->getValueAsDouble();
        auto xiaxianwei2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$xiaxianwei2$"));
        if (!xiaxianwei2Item) {
            throw std::runtime_error("$variable$xiaxianwei2 is not found");
        }
        xiaxianwei2 = xiaxianwei2Item->getValueAsDouble();
        auto baoguang2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$baoguang2$"));
        if (!baoguang2Item) {
            throw std::runtime_error("$variable$baoguang2 is not found");
        }
        baoguang2 = baoguang2Item->getValueAsDouble();
        auto zengyi2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$zengyi2$"));
        if (!zengyi2Item) {
            throw std::runtime_error("$variable$zengyi2 is not found");
        }
        zengyi2 = zengyi2Item->getValueAsDouble();
        auto xiangsudangliang2Item = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$xiangsudangliang2$"));
        if (!xiangsudangliang2Item) {
            throw std::runtime_error("$variable$xiangsudangliang2 is not found");
        }
        xiangsudangliang2 = xiangsudangliang2Item->getValueAsDouble();
        auto isZangWuItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isZangWu$"));
        if (!isZangWuItem) {
            throw std::runtime_error("$variable$isZangWu is not found");
        }
        isZangWu = isZangWuItem->getValueAsBool();
        auto isXiaoZangWuItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isXiaoZangWu$"));
        if (!isXiaoZangWuItem) {
            throw std::runtime_error("$variable$isXiaoZangWu is not found");
        }
        isXiaoZangWu = isXiaoZangWuItem->getValueAsBool();
        auto isJieTouItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isJieTou$"));
        if (!isJieTouItem) {
            throw std::runtime_error("$variable$isJieTou is not found");
        }
        isJieTou = isJieTouItem->getValueAsBool();
        auto isBodyItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isBody$"));
        if (!isBodyItem) {
            throw std::runtime_error("$variable$isBody is not found");
        }
        isBody = isBodyItem->getValueAsBool();
        auto isHuaPoItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isHuaPo$"));
        if (!isHuaPoItem) {
            throw std::runtime_error("$variable$isHuaPo is not found");
        }
        isHuaPo = isHuaPoItem->getValueAsBool();
        auto isSiLieItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isSiLie$"));
        if (!isSiLieItem) {
            throw std::runtime_error("$variable$isSiLie is not found");
        }
        isSiLie = isSiLieItem->getValueAsBool();
        auto isQueShiItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isQueShi$"));
        if (!isQueShiItem) {
            throw std::runtime_error("$variable$isQueShi is not found");
        }
        isQueShi = isQueShiItem->getValueAsBool();
        auto isWeiZhiQueXianItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$isWeiZhiQueXian$"));
        if (!isWeiZhiQueXianItem) {
            throw std::runtime_error("$variable$isWeiZhiQueXian is not found");
        }
        isWeiZhiQueXian = isWeiZhiQueXianItem->getValueAsBool();
        auto changeLanguageIndexItem = rw::oso::ObjectStoreCoreToItem(assembly.getItem("$variable$changeLanguageIndex$"));
        if (!changeLanguageIndexItem) {
            throw std::runtime_error("$variable$changeLanguageIndex is not found");
        }
        changeLanguageIndex = changeLanguageIndexItem->getValueAsInt();
    }

    inline SetConfig::SetConfig(const SetConfig& obj)
    {
        jishuguangdianyanshi = obj.jishuguangdianyanshi;
        paizhaoyanshi = obj.paizhaoyanshi;
        cipinguangdianjiange = obj.cipinguangdianjiange;
        fenliaojishu = obj.fenliaojishu;
        xiangjiguangdianpingbishijian = obj.xiangjiguangdianpingbishijian;
        defectIgnoreX = obj.defectIgnoreX;
        defectIgnoreY = obj.defectIgnoreY;
        tifeijiange1 = obj.tifeijiange1;
        tifeijiange2 = obj.tifeijiange2;
        shangxianwei1 = obj.shangxianwei1;
        xiaxianwei1 = obj.xiaxianwei1;
        baoguang1 = obj.baoguang1;
        zengyi1 = obj.zengyi1;
        xiangsudangliang1 = obj.xiangsudangliang1;
        shangxianwei2 = obj.shangxianwei2;
        xiaxianwei2 = obj.xiaxianwei2;
        baoguang2 = obj.baoguang2;
        zengyi2 = obj.zengyi2;
        xiangsudangliang2 = obj.xiangsudangliang2;
        isZangWu = obj.isZangWu;
        isXiaoZangWu = obj.isXiaoZangWu;
        isJieTou = obj.isJieTou;
        isBody = obj.isBody;
        isHuaPo = obj.isHuaPo;
        isSiLie = obj.isSiLie;
        isQueShi = obj.isQueShi;
        isWeiZhiQueXian = obj.isWeiZhiQueXian;
        changeLanguageIndex = obj.changeLanguageIndex;
    }

    inline SetConfig& SetConfig::operator=(const SetConfig& obj)
    {
        if (this != &obj) {
            jishuguangdianyanshi = obj.jishuguangdianyanshi;
            paizhaoyanshi = obj.paizhaoyanshi;
            cipinguangdianjiange = obj.cipinguangdianjiange;
            fenliaojishu = obj.fenliaojishu;
            xiangjiguangdianpingbishijian = obj.xiangjiguangdianpingbishijian;
            defectIgnoreX = obj.defectIgnoreX;
            defectIgnoreY = obj.defectIgnoreY;
            tifeijiange1 = obj.tifeijiange1;
            tifeijiange2 = obj.tifeijiange2;
            shangxianwei1 = obj.shangxianwei1;
            xiaxianwei1 = obj.xiaxianwei1;
            baoguang1 = obj.baoguang1;
            zengyi1 = obj.zengyi1;
            xiangsudangliang1 = obj.xiangsudangliang1;
            shangxianwei2 = obj.shangxianwei2;
            xiaxianwei2 = obj.xiaxianwei2;
            baoguang2 = obj.baoguang2;
            zengyi2 = obj.zengyi2;
            xiangsudangliang2 = obj.xiangsudangliang2;
            isZangWu = obj.isZangWu;
            isXiaoZangWu = obj.isXiaoZangWu;
            isJieTou = obj.isJieTou;
            isBody = obj.isBody;
            isHuaPo = obj.isHuaPo;
            isSiLie = obj.isSiLie;
            isQueShi = obj.isQueShi;
            isWeiZhiQueXian = obj.isWeiZhiQueXian;
            changeLanguageIndex = obj.changeLanguageIndex;
        }
        return *this;
    }

    inline SetConfig::operator rw::oso::ObjectStoreAssembly() const
    {
        rw::oso::ObjectStoreAssembly assembly;
        assembly.setName("$class$SetConfig$");
        auto jishuguangdianyanshiItem = std::make_shared<rw::oso::ObjectStoreItem>();
        jishuguangdianyanshiItem->setName("$variable$jishuguangdianyanshi$");
        jishuguangdianyanshiItem->setValueFromDouble(jishuguangdianyanshi);
        assembly.addItem(jishuguangdianyanshiItem);
        auto paizhaoyanshiItem = std::make_shared<rw::oso::ObjectStoreItem>();
        paizhaoyanshiItem->setName("$variable$paizhaoyanshi$");
        paizhaoyanshiItem->setValueFromDouble(paizhaoyanshi);
        assembly.addItem(paizhaoyanshiItem);
        auto cipinguangdianjiangeItem = std::make_shared<rw::oso::ObjectStoreItem>();
        cipinguangdianjiangeItem->setName("$variable$cipinguangdianjiange$");
        cipinguangdianjiangeItem->setValueFromInt(cipinguangdianjiange);
        assembly.addItem(cipinguangdianjiangeItem);
        auto fenliaojishuItem = std::make_shared<rw::oso::ObjectStoreItem>();
        fenliaojishuItem->setName("$variable$fenliaojishu$");
        fenliaojishuItem->setValueFromDouble(fenliaojishu);
        assembly.addItem(fenliaojishuItem);
        auto xiangjiguangdianpingbishijianItem = std::make_shared<rw::oso::ObjectStoreItem>();
        xiangjiguangdianpingbishijianItem->setName("$variable$xiangjiguangdianpingbishijian$");
        xiangjiguangdianpingbishijianItem->setValueFromDouble(xiangjiguangdianpingbishijian);
        assembly.addItem(xiangjiguangdianpingbishijianItem);
        auto defectIgnoreXItem = std::make_shared<rw::oso::ObjectStoreItem>();
        defectIgnoreXItem->setName("$variable$defectIgnoreX$");
        defectIgnoreXItem->setValueFromDouble(defectIgnoreX);
        assembly.addItem(defectIgnoreXItem);
        auto defectIgnoreYItem = std::make_shared<rw::oso::ObjectStoreItem>();
        defectIgnoreYItem->setName("$variable$defectIgnoreY$");
        defectIgnoreYItem->setValueFromDouble(defectIgnoreY);
        assembly.addItem(defectIgnoreYItem);
        auto tifeijiange1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        tifeijiange1Item->setName("$variable$tifeijiange1$");
        tifeijiange1Item->setValueFromInt(tifeijiange1);
        assembly.addItem(tifeijiange1Item);
        auto tifeijiange2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        tifeijiange2Item->setName("$variable$tifeijiange2$");
        tifeijiange2Item->setValueFromInt(tifeijiange2);
        assembly.addItem(tifeijiange2Item);
        auto shangxianwei1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        shangxianwei1Item->setName("$variable$shangxianwei1$");
        shangxianwei1Item->setValueFromDouble(shangxianwei1);
        assembly.addItem(shangxianwei1Item);
        auto xiaxianwei1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        xiaxianwei1Item->setName("$variable$xiaxianwei1$");
        xiaxianwei1Item->setValueFromDouble(xiaxianwei1);
        assembly.addItem(xiaxianwei1Item);
        auto baoguang1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        baoguang1Item->setName("$variable$baoguang1$");
        baoguang1Item->setValueFromDouble(baoguang1);
        assembly.addItem(baoguang1Item);
        auto zengyi1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        zengyi1Item->setName("$variable$zengyi1$");
        zengyi1Item->setValueFromDouble(zengyi1);
        assembly.addItem(zengyi1Item);
        auto xiangsudangliang1Item = std::make_shared<rw::oso::ObjectStoreItem>();
        xiangsudangliang1Item->setName("$variable$xiangsudangliang1$");
        xiangsudangliang1Item->setValueFromDouble(xiangsudangliang1);
        assembly.addItem(xiangsudangliang1Item);
        auto shangxianwei2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        shangxianwei2Item->setName("$variable$shangxianwei2$");
        shangxianwei2Item->setValueFromDouble(shangxianwei2);
        assembly.addItem(shangxianwei2Item);
        auto xiaxianwei2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        xiaxianwei2Item->setName("$variable$xiaxianwei2$");
        xiaxianwei2Item->setValueFromDouble(xiaxianwei2);
        assembly.addItem(xiaxianwei2Item);
        auto baoguang2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        baoguang2Item->setName("$variable$baoguang2$");
        baoguang2Item->setValueFromDouble(baoguang2);
        assembly.addItem(baoguang2Item);
        auto zengyi2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        zengyi2Item->setName("$variable$zengyi2$");
        zengyi2Item->setValueFromDouble(zengyi2);
        assembly.addItem(zengyi2Item);
        auto xiangsudangliang2Item = std::make_shared<rw::oso::ObjectStoreItem>();
        xiangsudangliang2Item->setName("$variable$xiangsudangliang2$");
        xiangsudangliang2Item->setValueFromDouble(xiangsudangliang2);
        assembly.addItem(xiangsudangliang2Item);
        auto isZangWuItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isZangWuItem->setName("$variable$isZangWu$");
        isZangWuItem->setValueFromBool(isZangWu);
        assembly.addItem(isZangWuItem);
        auto isXiaoZangWuItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isXiaoZangWuItem->setName("$variable$isXiaoZangWu$");
        isXiaoZangWuItem->setValueFromBool(isXiaoZangWu);
        assembly.addItem(isXiaoZangWuItem);
        auto isJieTouItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isJieTouItem->setName("$variable$isJieTou$");
        isJieTouItem->setValueFromBool(isJieTou);
        assembly.addItem(isJieTouItem);
        auto isBodyItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isBodyItem->setName("$variable$isBody$");
        isBodyItem->setValueFromBool(isBody);
        assembly.addItem(isBodyItem);
        auto isHuaPoItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isHuaPoItem->setName("$variable$isHuaPo$");
        isHuaPoItem->setValueFromBool(isHuaPo);
        assembly.addItem(isHuaPoItem);
        auto isSiLieItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isSiLieItem->setName("$variable$isSiLie$");
        isSiLieItem->setValueFromBool(isSiLie);
        assembly.addItem(isSiLieItem);
        auto isQueShiItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isQueShiItem->setName("$variable$isQueShi$");
        isQueShiItem->setValueFromBool(isQueShi);
        assembly.addItem(isQueShiItem);
        auto isWeiZhiQueXianItem = std::make_shared<rw::oso::ObjectStoreItem>();
        isWeiZhiQueXianItem->setName("$variable$isWeiZhiQueXian$");
        isWeiZhiQueXianItem->setValueFromBool(isWeiZhiQueXian);
        assembly.addItem(isWeiZhiQueXianItem);
        auto changeLanguageIndexItem = std::make_shared<rw::oso::ObjectStoreItem>();
        changeLanguageIndexItem->setName("$variable$changeLanguageIndex$");
        changeLanguageIndexItem->setValueFromInt(changeLanguageIndex);
        assembly.addItem(changeLanguageIndexItem);
        return assembly;
    }

    inline bool SetConfig::operator==(const SetConfig& obj) const
    {
        return jishuguangdianyanshi == obj.jishuguangdianyanshi && paizhaoyanshi == obj.paizhaoyanshi && cipinguangdianjiange == obj.cipinguangdianjiange && fenliaojishu == obj.fenliaojishu && xiangjiguangdianpingbishijian == obj.xiangjiguangdianpingbishijian && defectIgnoreX == obj.defectIgnoreX && defectIgnoreY == obj.defectIgnoreY && tifeijiange1 == obj.tifeijiange1 && tifeijiange2 == obj.tifeijiange2 && shangxianwei1 == obj.shangxianwei1 && xiaxianwei1 == obj.xiaxianwei1 && baoguang1 == obj.baoguang1 && zengyi1 == obj.zengyi1 && xiangsudangliang1 == obj.xiangsudangliang1 && shangxianwei2 == obj.shangxianwei2 && xiaxianwei2 == obj.xiaxianwei2 && baoguang2 == obj.baoguang2 && zengyi2 == obj.zengyi2 && xiangsudangliang2 == obj.xiangsudangliang2 && isZangWu == obj.isZangWu && isXiaoZangWu == obj.isXiaoZangWu && isJieTou == obj.isJieTou && isBody == obj.isBody && isHuaPo == obj.isHuaPo && isSiLie == obj.isSiLie && isQueShi == obj.isQueShi && isWeiZhiQueXian == obj.isWeiZhiQueXian && changeLanguageIndex == obj.changeLanguageIndex;
    }

    inline bool SetConfig::operator!=(const SetConfig& obj) const
    {
        return !(*this == obj);
    }

}

