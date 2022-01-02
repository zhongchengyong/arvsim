aux_source_directory(. ARCH)
aux_source_directory(instrs INSTRS)

add_library(arch ${ARCH} ${INSTRS})
