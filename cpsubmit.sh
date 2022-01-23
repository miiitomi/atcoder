
#!/bin/bash

problem_name=$1
file=$2
relative_file_dir_name=$3
contest_name=${relative_file_dir_name##*/}
url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_name}

# submit
~/opt/anaconda3/bin/oj submit --yes ${url} ${file}
