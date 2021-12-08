//
// Created by zhong on 12/8/21.
//

#ifndef ARVSIM_TESTS_TEST_HELPER_H_
#define ARVSIM_TESTS_TEST_HELPER_H_

#include <filesystem>

/**
 * @brief Find full path by relative path.
 */
inline std::string ResolvePath(const std::string &relPath) {
  namespace fs = std::filesystem;
  auto baseDir = fs::current_path();
  while (baseDir.has_parent_path()) {
    auto combinePath = baseDir / relPath;
    if (fs::exists(combinePath)) {
      return combinePath.string();
    }
    baseDir = baseDir.parent_path();
  }
  throw std::runtime_error("File not found!");
}
#endif //ARVSIM_TESTS_TEST_HELPER_H_
