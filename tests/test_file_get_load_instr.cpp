//
// Bareflank Hypervisor
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
// Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <bfelf_loader.h>
#include <test_fake_elf.h>

TEST_CASE("bfelf_file_get_load_instr: invalid elf file")
{
    bfelf_load_instr *instr = nullptr;

    auto ret = bfelf_file_get_load_instr(nullptr, 0, &instr);
    CHECK(ret == BFELF_ERROR_INVALID_ARG);
}

TEST_CASE("bfelf_file_get_load_instr: include index")
{
    auto ret = 0LL;
    bfelf_file_t ef = {};
    bfelf_load_instr *instr = nullptr;

    auto &&data = get_fake_elf();
    auto &&buff = std::get<0>(data);
    auto &&size = std::get<1>(data);

    ret = bfelf_file_init(buff.get(), size, &ef);
    CHECK(ret == BFELF_SUCCESS);

    ret = bfelf_file_get_load_instr(&ef, 10, &instr);
    CHECK(ret == BFELF_ERROR_INVALID_INDEX);
}

TEST_CASE("bfelf_file_get_load_instr: invalid instr")
{
    auto ret = 0LL;
    bfelf_file_t ef = {};

    auto &&data = get_fake_elf();
    auto &&buff = std::get<0>(data);
    auto &&size = std::get<1>(data);

    ret = bfelf_file_init(buff.get(), size, &ef);
    CHECK(ret == BFELF_SUCCESS);

    ret = bfelf_file_get_load_instr(&ef, 0, nullptr);
    CHECK(ret == BFELF_ERROR_INVALID_ARG);
}

TEST_CASE("bfelf_file_get_load_instr: success")
{
    auto ret = 0LL;
    bfelf_file_t ef = {};
    bfelf_load_instr *instr = nullptr;

    auto &&data = get_fake_elf();
    auto &&buff = std::get<0>(data);
    auto &&size = std::get<1>(data);

    ret = bfelf_file_init(buff.get(), size, &ef);
    CHECK(ret == BFELF_SUCCESS);

    ret = bfelf_file_get_load_instr(&ef, 0, &instr);
    CHECK(ret == BFELF_SUCCESS);
}
