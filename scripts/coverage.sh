#!/usr/bin/env bash
set -euo pipefail

modules=(
  "Heap"
  "TabelaHash"
  "ListaEncadeada"
  "ListaDuplamenteEncadeada"
  "GrafoListaAdjacencia"
  "AVL"
  "AlgoritmosGrafos"
)

coverage_flags="-pedantic-errors -Wall -Wextra -Werror -g -O0 --coverage"
coverage_ldflags="-lm --coverage"

rm -rf coverage
mkdir -p coverage/gcov

echo "== Coverage report ==" | tee coverage/summary.txt
for module in "${modules[@]}"; do
  echo "-- ${module} --" | tee -a coverage/summary.txt
  make -C "${module}" clean >/dev/null
  make -C "${module}" test CCFLAGS="${coverage_flags}" LDFLAGS="${coverage_ldflags}" >/tmp/coverage-${module}.log 2>&1

  if command -v gcov >/dev/null 2>&1; then
    find "${module}/build/objects" -name '*.gcda' -print0 \
      | xargs -0 -r gcov -o "${module}/build/objects/src" \
      | tee -a coverage/summary.txt >/dev/null || true
    mv ./*.gcov coverage/gcov/ 2>/dev/null || true
  fi

  make -C "${module}" clean >/dev/null
  echo "coverage: completed" | tee -a coverage/summary.txt
done

echo "Coverage artifacts written to coverage/" | tee -a coverage/summary.txt
