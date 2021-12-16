//
// Created by zhong on 9/20/21.
//

#include "processor.hh"
#include <iostream>

using namespace arv_core;
void AtomicProcessor::Process() {
  std::cout << "Atomic Tick..." << std::endl;
  ++m_stat.m_cycle;
  ++m_stat.m_inst;
  LOG_DEBUG << "cycle:" << m_stat.m_cycle << ENDL;
}

void O3Processor::Process() {

}
