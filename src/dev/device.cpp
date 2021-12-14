#include "device.hh"
#include <iostream>

using namespace arv_dev;

bool Memory::Write(addr_t addr, size_t len, const uint8_t *bytes) {
  std::vector<uint8_t> data(bytes, bytes + len);
  return LoadStore(addr, len, data, true);
}

bool Memory::Read(addr_t addr, size_t len, std::vector<uint8_t> &res) {
  return LoadStore(addr, len, res, false);
}

bool Memory::LoadStore(addr_t addr, size_t len, std::vector<uint8_t> &bytes, bool store) {
  size_t offset = 0;
  while (len > 0) {
    size_t page = addr >> PAGE_SHFIT, page_offset = addr % PAGE_SIZE;
    size_t size = std::min(len, PAGE_SIZE - page_offset);
    if (m_data.find(page) != m_data.end()) {
      if (store)
        std::copy(bytes.data() + offset, bytes.data() + offset + size, m_data[page].data() + page_offset);
      else
        bytes.insert(bytes.end(), m_data[page].data() + offset, m_data[page].data() + offset + size);
    } else {
      std::array<uint8_t, PAGE_SIZE> values{};
      if (store) {
        std::copy(bytes.data() + offset, bytes.data() + offset + size, values.data());
      } else {
        // Copy data to bytes, which value is zero.
        bytes.insert(bytes.end(), values.data(), values.data() + size);
      }
      m_data[page] = values;
    }
    addr += size;
    len -= size;
    offset += size;
  }
  return true;
}

