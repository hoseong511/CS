# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hossong <hossong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 11:38:54 by hossong           #+#    #+#              #
#    Updated: 2021/09/13 13:40:39 by hoho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## for Mac ## 
# Run settings : ./compile.sh 
# Command : ftcc
# `ftcc` command is a build and execute your project.

if [ -z `grep -n 'ftcc' ~/.bash_profile | sed -e 's/:.*//g'` ] ; then
	echo "alias ftcc='gcc -Wall -Wextra -Werror *.c -o exe && ./exe && rm exe'" >> ~/.bash_profile
	val=`grep -n 'bash_profile' ~/.zshrc | sed -e 's/:.*//g'`
	if [ -z $val ] ; then
		echo "source ~/.bash_profile" >> ~/.zshrc
		source ~/.zshrc
	fi
		echo 'Settings success!'
else
	echo 'Already settings'
fi


