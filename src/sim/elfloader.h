// See LICENSE for license details.

#ifndef _ELFLOADER_H
#define _ELFLOADER_H

#include "elf.h"
#include "dev/mmu.h"

#include <map>
#include <string>

namespace arv_dev {
class MMU;
}

namespace arv_sim {
std::map<std::string, uint64_t> LoadElf(const char *fn, arv_dev::MMU *memif, arv_common::reg_t *entry);
}

#endif
