// See LICENSE for license details.

#ifndef _ELFLOADER_HH
#define _ELFLOADER_HH

#include "elf.hh"
#include "dev/mmu.hh"

#include <map>
#include <string>

namespace arv_dev {
class MMU;
}

namespace arv_sim {
std::map<std::string, uint64_t> LoadElf(const char *fn, arv_dev::MMU *memif,reg_t *entry);
}

#endif