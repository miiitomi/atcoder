export $(cat .env | grep -v ^# | xargs)
/opt/homebrew/Caskroom/miniforge/base/bin/oj login -u $ATCODER_USER -p $ATCODER_PASS "https://atcoder.jp/"
