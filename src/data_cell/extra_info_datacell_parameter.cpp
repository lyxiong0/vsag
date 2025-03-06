
// Copyright 2024-present the vsag project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "extra_info_datacell_parameter.h"

#include <fmt/format-inl.h>

#include "inner_string_params.h"

namespace vsag {
ExtraInfoDataCellParameter::ExtraInfoDataCellParameter() = default;

void
ExtraInfoDataCellParameter::FromJson(const JsonType& json) {
    CHECK_ARGUMENT(json.contains(IO_PARAMS_KEY),
                   fmt::format("extra info interface parameters must contains {}", IO_PARAMS_KEY));
    this->io_parameter_ = IOParameter::GetIOParameterByJson(json[IO_PARAMS_KEY]);
    CHECK_ARGUMENT(json.contains(EXTRA_INFO_SIZE),
                   fmt::format("extra info interface parameters must contains {}", EXTRA_INFO_SIZE));
    this->extra_info_size_ = json[EXTRA_INFO_SIZE];
}

JsonType
ExtraInfoDataCellParameter::ToJson() {
    JsonType json;
    json[IO_PARAMS_KEY] = this->io_parameter_->ToJson();
    json[EXTRA_INFO_SIZE] = this->extra_info_size_;
    return json;
}
}  // namespace vsag
