// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include <fstream>
#include <string>
#include "storage/IOWriter.h"

namespace milvus {
namespace storage {

class DiskIOWriter : public IOWriter {
 public:
    DiskIOWriter() = default;
    ~DiskIOWriter() = default;

    // No copy and move
    DiskIOWriter(const DiskIOWriter&) = delete;
    DiskIOWriter(DiskIOWriter&&) = delete;

    DiskIOWriter&
    operator=(const DiskIOWriter&) = delete;
    DiskIOWriter&
    operator=(DiskIOWriter&&) = delete;

    void
    open(const std::string& name) override;

    void
    write(void* ptr, size_t size) override;

    size_t
    length() override;

    void
    close() override;

 public:
    std::string name_;
    size_t len_;
    std::fstream fs_;
};

}  // namespace storage
}  // namespace milvus
