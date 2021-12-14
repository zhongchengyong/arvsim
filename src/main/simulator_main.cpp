//
// Created by zhong on 12/13/21.
//

#include "sim/simulator.hh"

using namespace arv_sim;

int main() {
  Simulator simulator;
  simulator.LoadPayload("/home/zhong/study/simulator/arvsim/tests/ut/data/rv64ui-p-addi");
  simulator.Run(0);
  simulator.Run(0);
}