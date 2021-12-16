//
// Created by kode.zhong on 2020/11/14.
//

#ifndef RISCV_COMMON_LOGGER_H_
#define RISCV_COMMON_LOGGER_H_

#include <iostream>
#include <sstream>

// Define for override << std::endl;
using CoutType = std::basic_ostream<char, std::char_traits<char>>;
using EndlType = CoutType &(CoutType &);

#define ENDL std::endl

enum class LogLevel {
  FATAL,
  ERROR,
  INFO,
  DEBUG
};

/**
 * Usage: LOG_ERROR() << xxx << std::endl;
 */
class Logger {
 public:
  explicit Logger(LogLevel level, std::ostream &ostream) : m_ostream{ostream} {
    switch (level) {
      case LogLevel::FATAL: {
        m_ss << "Fatal: ";
        break;
      }
      case LogLevel::ERROR: {
        m_ss << "Error: ";
        break;
      }
      case LogLevel::DEBUG: {
        m_ss << "Debug: ";
        break;
      }
      case LogLevel::INFO:
      default: {
        m_ss << "Info:  ";
        break;
      }
    }
  }

  Logger &operator<<(EndlType func_ptr) {
    m_ostream << m_ss.str();
    func_ptr(m_ostream);
    m_ss.clear();
    return *this;
  }

  template<typename T>
  Logger &operator<<(T t) {
    m_ss << t;
    return *this;
  }

 private:
  std::stringstream m_ss;
  CoutType &m_ostream;
};

#define LOG_FATAL Logger(LogLevel::FATAL, std::cerr)
#define LOG_ERROR Logger(LogLevel::ERROR, std::cerr)
#define LOG_INFO  Logger(LogLevel::INFO,  std::cout)
#define LOG_DEBUG Logger(LogLevel::DEBUG, std::cout)

//#define LEX_ERROR(line, msg) LOG_ERROR << "Line" << line << ", " \
//                             << msg << "." << std::endl

inline void Error(size_t line, const std::string &msg) {
  std::cerr << "[line " << line << "] Error: " << msg;
}

#endif //RISCV_COMMON_LOGGER_H_