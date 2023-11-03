# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm16
    contrib/libs/llvm16/lib/DebugInfo/DWARF
    contrib/libs/llvm16/lib/MC
    contrib/libs/llvm16/lib/Object
    contrib/libs/llvm16/lib/Support
    contrib/libs/llvm16/lib/TargetParser
)

ADDINCL(
    contrib/libs/llvm16/lib/DebugInfo/GSYM
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    DwarfTransformer.cpp
    ExtractRanges.cpp
    FileWriter.cpp
    FunctionInfo.cpp
    GsymCreator.cpp
    GsymReader.cpp
    Header.cpp
    InlineInfo.cpp
    LineTable.cpp
    LookupResult.cpp
    ObjectFileTransformer.cpp
)

END()