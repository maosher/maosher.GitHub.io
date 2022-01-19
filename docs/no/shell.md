# shell command
## grep 

## find

## sed
**按行来匹配修改数据，并输出缓冲区**  
sed [选项] [脚本命令] 文件名  
-e 脚本命令	该选项会将其后跟的脚本命令添加到已有的命令中。  
-f 脚本命令文件	该选项会将其后文件中的脚本命令添加到已有的命令中。  
-n	默认情况下，sed 会在所有的脚本指定执行完毕后，会自动输出处理后的内容，而该选项会屏蔽启动输出，需使用 print 命令来完成输出。  
-i	此选项会直接修改源文件，要慎用。  

sed 's/test/trial/g' a.txt 全替换  没有g 只替换一次
sed 's/test/trial/2' a.txt 替换第2次出现

vim 下/s 一样的
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




