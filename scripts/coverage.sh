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

echo "== Coverage report =="
for module in "${modules[@]}"; do
  echo "-- ${module} --"
  make -C "${module}" clean >/dev/null
  make -C "${module}" coverage >/dev/null
  if command -v gcov >/dev/null 2>&1; then
    find "${module}/build/objects" -name '*.gcda' -print0 | xargs -0 -r gcov -o "${module}/build/objects/src" >/dev/null 2>&1 || true
  fi
  make -C "${module}" clean >/dev/null
  echo "coverage: completed"
done
