/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_HDI_DISPLAY_V1_0_IDISPLAY_COMPOSER_INTERFACE_H
#define OHOS_HDI_DISPLAY_V1_0_IDISPLAY_COMPOSER_INTERFACE_H

#include <vector>
#include "buffer_handle.h"
#include "common/include/display_common.h"
#include "iproxy_broker.h"
#include "v1_0/display_composer_type.h"

namespace OHOS {
namespace HDI {
namespace Display {
namespace Composer {
namespace V1_0 {
using namespace OHOS::HDI::Display::Composer::V1_0;

class IDisplayComposerInterface : public virtual RefBase {
public:
    virtual ~IDisplayComposerInterface() = default;
    static IDisplayComposerInterface* Get();
    virtual bool AddDeathRecipient(const sptr<IRemoteObject::DeathRecipient>& recipient) = 0;
    virtual bool RemoveDeathRecipient() = 0;
    /* device func */
    virtual int32_t RegHotPlugCallback(HotPlugCallback cb, void* data) = 0;
    virtual int32_t GetDisplayCapability(uint32_t devId, DisplayCapability& info) = 0;
    virtual int32_t GetDisplaySupportedModes(uint32_t devId, std::vector<DisplayModeInfo>& modes) = 0;
    virtual int32_t GetDisplayMode(uint32_t devId, uint32_t& modeId) = 0;
    virtual int32_t SetDisplayMode(uint32_t devId, uint32_t modeId) = 0;
    virtual int32_t GetDisplayPowerStatus(uint32_t devId, DispPowerStatus& status) = 0;
    virtual int32_t SetDisplayPowerStatus(uint32_t devId, DispPowerStatus status) = 0;
    virtual int32_t GetDisplayBacklight(uint32_t devId, uint32_t& level) = 0;
    virtual int32_t SetDisplayBacklight(uint32_t devId, uint32_t level) = 0;
    virtual int32_t GetDisplayProperty(uint32_t devId, uint32_t id, uint64_t& value) = 0;
    virtual int32_t GetDisplayCompChange(uint32_t devId, std::vector<uint32_t>& layers,
        std::vector<int32_t>& types) = 0;
    virtual int32_t SetDisplayClientCrop(uint32_t devId, const IRect& rect) = 0;
    virtual int32_t SetDisplayClientBuffer(uint32_t devId, const BufferHandle& buffer, int32_t fence) = 0;
    virtual int32_t SetDisplayClientDamage(uint32_t devId, std::vector<IRect>& rects) = 0;
    virtual int32_t SetDisplayVsyncEnabled(uint32_t devId, bool enabled) = 0;
    virtual int32_t RegDisplayVBlankCallback(uint32_t devId, VBlankCallback cb, void* data) = 0;
    virtual int32_t GetDisplayReleaseFence(uint32_t devId, std::vector<uint32_t>& layers,
        std::vector<int32_t>& fences) = 0;
    virtual int32_t CreateVirtualDisplay(uint32_t width, uint32_t height, int32_t& format, uint32_t& devId) = 0;
    virtual int32_t DestroyVirtualDisplay(uint32_t devId) = 0;
    virtual int32_t SetVirtualDisplayBuffer(uint32_t devId, const BufferHandle& buffer, const int32_t fence) = 0;
    virtual int32_t SetDisplayProperty(uint32_t devId, uint32_t id, uint64_t value) = 0;
    virtual int32_t Commit(uint32_t devId, int32_t& fence) = 0;
    virtual int32_t GetDisplaySupportedColorGamuts(uint32_t devId, std::vector<ColorGamut>& gamuts) = 0;
    virtual int32_t GetDisplayColorGamut(uint32_t devId, ColorGamut& gamut) = 0;
    virtual int32_t SetDisplayColorGamut(uint32_t devId, const ColorGamut& gamut) = 0;
    virtual int32_t GetDisplayGamutMap(uint32_t devId, GamutMap& gamutMap) = 0;
    virtual int32_t SetDisplayGamutMap(uint32_t devId, const GamutMap& gamutMap) = 0;
    virtual int32_t SetDisplayColorTransform(uint32_t devId, const std::vector<float>& matrix) = 0;
    virtual int32_t GetHDRCapabilityInfos(uint32_t devId, HDRCapability& info) = 0;
    virtual int32_t GetSupportedMetadataKey(uint32_t devId, std::vector<HDRMetadataKey>& keys) = 0;
    /* layer func */
    virtual int32_t CreateLayer(uint32_t devId, const LayerInfo& layerInfo, uint32_t& layerId) = 0;
    virtual int32_t DestroyLayer(uint32_t devId, uint32_t layerId) = 0;
    virtual int32_t PrepareDisplayLayers(uint32_t devId, bool& needFlushFb) = 0;
    virtual int32_t SetLayerAlpha(uint32_t devId, uint32_t layerId, const LayerAlpha& alpha) = 0;
    virtual int32_t SetLayerRegion(uint32_t devId, uint32_t layerId, const IRect& rect) = 0;
    virtual int32_t SetLayerCrop(uint32_t devId, uint32_t layerId, const IRect& rect) = 0;
    virtual int32_t SetLayerZorder(uint32_t devId, uint32_t layerId, uint32_t zorder) = 0;
    virtual int32_t SetLayerPreMulti(uint32_t devId, uint32_t layerId, bool preMul) = 0;
    virtual int32_t SetLayerTransformMode(uint32_t devId, uint32_t layerId, TransformType type) = 0;
    virtual int32_t SetLayerDirtyRegion(uint32_t devId, uint32_t layerId, std::vector<IRect>& regions) = 0;
    virtual int32_t SetLayerVisibleRegion(uint32_t devId, uint32_t layerId, std::vector<IRect>& rects) = 0;
    virtual int32_t SetLayerBuffer(uint32_t devId, uint32_t layerId, const BufferHandle& buffer, int32_t fence) = 0;
    virtual int32_t SetLayerCompositionType(uint32_t devId, uint32_t layerId, CompositionType type) = 0;
    virtual int32_t SetLayerBlendType(uint32_t devId, uint32_t layerId, BlendType type) = 0;
    virtual int32_t SetLayerColorTransform(uint32_t devId, uint32_t layerId, const std::vector<float>& matrix) = 0;
    virtual int32_t SetLayerColorDataSpace(uint32_t devId, uint32_t layerId, const ColorDataSpace colorSpace) = 0;
    virtual int32_t GetLayerColorDataSpace(uint32_t devId, uint32_t layerId, ColorDataSpace& colorSpace) = 0;
    virtual int32_t SetLayerMetaData(uint32_t devId, uint32_t layerId, const std::vector<HDRMetaData>& metaData) = 0;
    virtual int32_t SetLayerMetaDataSet(uint32_t devId, uint32_t layerId, HDRMetadataKey key,
         const std::vector<uint8_t>& metaData) = 0;
    virtual int32_t GetSupportedPresentTimestamp(uint32_t devId, uint32_t layerId, PresentTimestampType& type) = 0;
    virtual int32_t GetHwPresentTimestamp(uint32_t devId, uint32_t layerId, PresentTimestamp& pts) = 0;
    virtual int32_t SetLayerTunnelHandle(uint32_t devId, uint32_t layerId, const ExtDataHandle& handle) = 0;
    virtual int32_t SetLayerMaskInfo(uint32_t devId, uint32_t layerId, const MaskInfo maskInfo) = 0;
};
} // V1_0
} // Composer
} // Display
} // HDI
} // OHOS
#endif // OHOS_HDI_DISPLAY_V1_0_IDISPLAY_COMPOSER_INTERFACE_H
