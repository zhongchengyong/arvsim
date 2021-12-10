#include "simulator.h"
#include "elfloader.h"

#include "dev/device.h"
#include "common/sim_define.h"

void Simulator::LoadPayload(const std::string &file_name) {
  reg_t entry;
  arv_sim::LoadElf(file_name.c_str(), &mmu, &entry);
}

void Simulator::Run(size_t n) {

}

int main() {
  Simulator simulator;
  simulator.LoadPayload("/home/zhong/study/simulator/arvsim/tests/ut/data/rv64ui-p-addi");
  simulator.Run(0);
}
