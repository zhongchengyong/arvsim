//
// Created by zhong on 12/19/21.
//

#include "commit.hh"
#include "processor.hh"

#include "arch/result.hh"
#include "common/logger.hh"

void arv_core::Commit::Tick() {
  std::deque<ResultUP> &results = m_processor.FromIEW().results;
  LOG_INFO << "Commit result" << std::endl;
  LOG_INFO << "Commit result2";
  for (auto &result: results) {
    result->Do();
    LOG_INFO << "Commit result;";
    results.pop_front();
  }
}
