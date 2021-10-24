#ifndef ARVSIM_SRC_SIM_SIMULATOR_H_
#define ARVSIM_SRC_SIM_SIMULATOR_H_
#include <string>

class Simulator {
 public:
  void LoadPayload(const std::string& file_name);
};

#endif //ARVSIM_SRC_SIM_SIMULATOR_H_
