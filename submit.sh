problem_name=$1
file=$2
relative_file_dir_name=$3
contest_name=${relative_file_dir_name##*/}
contest_type=`echo ${relative_file_dir_name%/*}`

if [ ${contest_name} = tessoku-book ];
then
    url=https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_${problem_name}
elif [ ${contest_name} = math-and-algorithm ];
then
    url=https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_${problem_name}
elif [ ${contest_name:0:3} = ahc ];
then
    url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_a
elif [ ${contest_type} = mayocon ] || [ ${contest_type} = mosoonv ] || [ ${contest_type} = miiitomi ] || [ ${contest_type} = typical90 ] || [ ${contest_type} = PAST ];
then
    url=`head -n 1 ${file}`
    url=${url:3}
else
    url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_name}
fi

# submit
oj submit --yes ${url} ${file}
