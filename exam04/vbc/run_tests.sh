#!/usr/bin/env bash
set -u

# vbc test runner based on subject examples.
# It checks output and expected exit code.

bin="./vbc"
if [ ! -x "$bin" ]; then
  echo "Error: $bin not found or not executable"
  exit 1
fi

if [ -t 1 ]; then
  GREEN='\033[0;32m'
  RED='\033[0;31m'
  RESET='\033[0m'
else
  GREEN=''
  RED=''
  RESET=''
fi

long_expr="2*4+9+3+2*1+5+1+6+6*1*1+8*0+0+5+0*4*9*5*8+9*7+5*1+3+1+4*5*7*3+0*3+4*8+8+8+4*0*5*3+5+4+5*7+9+6*6+7+9*2*6*9+2+1*3*7*1*1*5+1+2+7+4+3*4*2+0+4*4*2*2+6+7*5+9+0+8*4+6*7+5+4*4+2+5*5+1+6+3*5*9*9+7*4*3+7+4*9+3+0+1*8+1+2*9*4*5*1+0*1*9+5*3*5+9*6+5*4+5+5*8*6*4*9*2+0+0+1*5*3+6*8*0+0+2*3+7*5*6+8+6*6+9+3+7+0*0+5+2*8+2*7*2+3+9*1*4*8*7*9+2*0+1*6*4*2+8*8*3*1+8+2*4+8*3+8*3+9*5+2*3+9*5*6*4+3*6*6+7+4*8+0+2+9*8*0*6*8*1*2*7+0*5+6*5+0*2+7+2+3+8*7+6+1*3+5+4*5*4*6*1+4*7+9*0+4+9*8+7+5+6+2+6+1+1+1*6*0*9+7+6*2+4*4+1*6*2*9+3+0+0*1*8+4+6*2+6+2*7+7+0*9+6+2*1+6*5*2*3*5*2*6*4+2*9*2*4*5*2*2*3+8+8*3*2*3+0*5+9*6+8+3*1+6*9+8+9*2*0+2"

run_case() {
  expr="$1"
  expected_out="$2"
  expected_code="$3"

  out="$($bin "$expr" 2>&1)"
  code=$?

  if [ "$out" = "$expected_out" ] && [ "$code" -eq "$expected_code" ]; then
    printf "%bPASS%b  Input: %s\n" "$GREEN" "$RESET" "$expr"
  else
    printf "%bFAIL%b  Input: %s\n" "$RED" "$RESET" "$expr"
    printf "  Expected out : \"%s\"\n" "$expected_out"
    printf "  Actual out   : \"%s\"\n" "$out"
    printf "  Expected code: %s\n" "$expected_code"
    printf "  Actual code  : %s\n" "$code"
    fail_count=$((fail_count + 1))
  fi
}

fail_count=0

run_case "1" "1" 0
run_case "2+3" "5" 0
run_case "3*4+5" "17" 0
run_case "3+4*5" "23" 0
run_case "(3+4)*5" "35" 0
run_case "(((((2+2)*2+2)*2+2)*2+2)*2+2)*2" "188" 0
run_case "1+" "Unexpected end of input" 1
run_case "1+2)" "Unexpected token ')'" 1
run_case "1+2+3+4+5" "15" 0
run_case "$long_expr" "94305" 0
run_case "(1)" "1" 0
run_case "(((((((3)))))))" "3" 0
run_case "(1+2)*3" "9" 0
run_case "((6*6+7+5+8)*(1+0+4*8+7)+2)+4*(1+2)" "2254" 0
run_case "((1+3)*12+(3*(2+6))" "Unexpected token '2'" 1

if [ "$fail_count" -ne 0 ]; then
  printf "\n%d TEST(S) FAILED\n" "$fail_count"
  exit 1
fi

printf "\nAll tests passed.\n"
exit 0
