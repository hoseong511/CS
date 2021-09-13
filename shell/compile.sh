# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hossong <hossong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 11:38:54 by hossong           #+#    #+#              #
#    Updated: 2021/09/13 12:54:36 by hossong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## for Mac ## 
# Run settings : ./compile.sh 
# Command : ftcc
# `ftcc` command is a build and execute your project.

val=`grep -n 'ftcc' ~/.bash_profile | sed -e 's/:.*//g' -e 's/ //g'`
if [ -z $val ] ; then
	echo "alias ftcc='gcc -Wall -Wextra -Werror *.c -o exe && ./exe && rm exe'" >> ~/.bash_profile
	echo "source ~/.bash_profile" >> ~./zshrc
	source ~./zshrc
else
	echo 'Already settings'
fi


