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
  Tick();
}

void O3Processor::Tick() {
  m_fetch.Tick();
  m_decode.Tick();
  m_rename.Tick();
  m_iew.Tick();
  m_commit.Tick();
}

O3Processor::O3Processor(MMU &mmu) : Processor{mmu},
                                     m_time_buffer{},
                                     m_fetch(*this, 0),
                                     m_decode(*this),
                                     m_rename(*this),
                                     m_iew(*this),
                                     m_commit(*this) {}

FetchStruct &O3Processor::FromFetch() {
  return m_time_buffer.m_fetch;
}

DecodeStruct &O3Processor::FromDecode() {
  return m_time_buffer.m_decode;
}

RenameStruct &O3Processor::FromRename() {
  return m_time_buffer.m_rename;
}

IEWStruct &O3Processor::FromIEW() {
  return m_time_buffer.m_iew;
}

CommitStruct &O3Processor::FromCommit() {
  return m_time_buffer.m_commit;
}
