#!/bin/bash

# Files
SUBJECT_LOG="19920104_091532.log"
MY_LOG="my.log"
REF_CLEAN="ref_clean.tmp"
MY_CLEAN="my_clean.tmp"

# --- CLEAN MODE ---
if [ "$1" == "clean" ]; then
    echo "🧹 Cleaning temporary files..."
    rm -f $MY_LOG $REF_CLEAN $MY_CLEAN
    make fclean
    echo "✨ Clean complete."
    exit 0
fi

# --- TEST MODE ---

# 1. Check if the subject log exists
if [ ! -f "$SUBJECT_LOG" ]; then
    echo "❌ Error: Could not find $SUBJECT_LOG"
    exit 1
fi

# 2. Compile silently
echo "⚙️  Compiling..."
make re > /dev/null

# 3. Run your program
echo "🏃 Running ./account..."
./account > $MY_LOG

# 4. Strip timestamps (Cut everything before the first space)
#    -d " "  : use space as delimiter
#    -f 2-   : keep field 2 and everything after it
cut -d " " -f 2- $SUBJECT_LOG > $REF_CLEAN
cut -d " " -f 2- $MY_LOG > $MY_CLEAN

# 5. Compare
echo "👀 Comparing logs..."
DIFF=$(diff $REF_CLEAN $MY_CLEAN)

if [ "$DIFF" == "" ]; then
    echo -e "\033[32m✅ SUCCESS! Your output matches the subject log perfectly.\033[0m"
else
    echo -e "\033[31m❌ FAILURE! The logs are different.\033[0m"
    echo "-------------------------------------------------"
    diff $REF_CLEAN $MY_CLEAN
    echo "-------------------------------------------------"
fi