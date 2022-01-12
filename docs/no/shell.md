# shell command
## grep 

## find

## sed

## awk 
**对文件内空按指定分隔符分隔后输出**  
awk [选项参数] 'script' var=value file(s)  
awk [选项参数] -f scriptfile var=value file(s) 

>\# 每行按空格或TAB分割，输出文本中的1、4项  
>awk '{print $1,$4}' log.txt  
>\# 格式化输出  
>awk '{printf "%-8s %-10s\n",$1,$4}' log.txt  
>\# 使用","分割  
>awk -F, '{print $1,$2}'   log.txt  
>\# 使用多个分隔符.先使用空格分割，然后对分割结果再使用","分割  
>awk -F '[ ,]'  '{print $1,$2,$5}'   log.txt




