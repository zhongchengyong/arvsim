#include "dev/mmu.h"
#include "dev/device.h"
#include "sim/simulator.h"
#include "sim/elfloader.h"
#include "test_helper.h"

#include "gtest/gtest.h"

#include <filesystem>

class TestSimulator : public ::testing::Test {
 public:
  TestSimulator() : sim{}, memory{}, mmu{memory} {}
  void SetUp() override {
    std::string file_name = "tests/ut/data/rv64ui-p-addi";
    input_elf = ResolvePath(file_name);
    reg_t entry;
    arv_sim::LoadElf(input_elf.c_str(), &mmu, &entry);
  }
 protected:
  std::string input_elf;
  Simulator sim;
  arv_dev::Memory memory;
  arv_dev::MMU mmu;
};

TEST_F(TestSimulator, LoadProgramTest) {
  std::vector<uint8_t> program;
  memory.Read(0x80000000, 1148, program);
  EXPECT_EQ(program[0], 0x6f);
  EXPECT_EQ(program[0x43c], 0x73);
  std::vector<uint8_t> to_host_data;
  memory.Read(0x80001000,0x48, to_host_data);
  EXPECT_EQ(to_host_data[0], 0);
}
