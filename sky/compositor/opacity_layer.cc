// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sky/compositor/opacity_layer.h"

namespace sky {
namespace compositor {

OpacityLayer::OpacityLayer() {
}

OpacityLayer::~OpacityLayer() {
}

void OpacityLayer::Paint(GrContext* context, SkCanvas* canvas) {
  SkColor color = SkColorSetARGB(alpha_, 0, 0, 0);
  RefPtr<SkColorFilter> colorFilter = adoptRef(
      SkColorFilter::CreateModeFilter(color, SkXfermode::kSrcOver_Mode));
  SkPaint paint;
  paint.setColorFilter(colorFilter.get());
  canvas->saveLayer(&paint_bounds(), &paint);
  PaintChildren(context, canvas);
  canvas->restore();
}

}  // namespace compositor
}  // namespace sky
