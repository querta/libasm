/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:37:18 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/19 13:38:38 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

int main()
{
	char *empty = "";
	char *strlong = "asdfghjklzxcvbnmqwertyuiop[];0asdfghjklzxcvbnmqwertyuiop[]0asdfghjklzxcvbnmqwertyuiop[];012345657890";
	char *str = "prosto stroka";
	char dstlong[101];
	char dstlong_orig[101];
	char dst[14];
	char dst_orig[14];
	char dstempty[5];
	char dstempty_orig[5];

	printf("--=== ft_strlen ===---\n");
	printf("empty\t orig:%zu my:%zu\nlong\t orig:%zu my:%zu\nregular\t orig:%zu my:%zu\n",
		strlen(empty), ft_strlen(empty), strlen(strlong), ft_strlen(strlong),
		strlen(str), ft_strlen(str));
		
	printf("--=== ft_strcpy ===---\n");
	printf("empty\n\torig:\t%s \n\tmy:\t%s \nlong\n\torig:\t%s \n\tmy:\t%s \nregular\n\torig:\t%s\n\tmy:\t%s\n", 
		strcpy(dstempty_orig, empty), ft_strcpy(dstempty, empty), 
		strcpy(dstlong_orig, strlong), ft_strcpy(dstlong, strlong),
		strcpy(dst_orig, str), ft_strcpy(dst, str));

	printf("--=== ft_strcmp ===---\n");

	char *str1 = ""; 
	char *str2 = "";
	char *str3 = "Ййаы";
	char *str4 = "aaaa";
	char *nums1 = "1234";
	char *nums2 = "4321";
	printf("\e[1;37m\n str1:str2\torig:my\n\e[0m");
	printf(" %s:%s \t%d:%d \n %s:%s \t%d:%d \n %s:%s \t%d:%d \n %s:%s \t%d:%d \n %s:%s \t%d:%d \n %s:%s \t%d:%d \n",
		str1, str2, strcmp(str1, str2), ft_strcmp(str1, str2),
		str1, str3, strcmp(str1, str3), ft_strcmp(str1, str3),
		str3, str1, strcmp(str3, str1), ft_strcmp(str3, str1),
		str4, str4, strcmp(str4, str4), ft_strcmp(str4, str4),
		nums1, str3, strcmp(nums1, str3), ft_strcmp(nums1, str3),
		nums1, nums2, strcmp(nums1, nums2), ft_strcmp(nums1, nums2)
		);
	printf("\n");
	printf("--=== ft_write ===---\n");

	int fd;
	int written;
	int written_or;
	char *buf = "slovo123";

	printf("\tstdout\n");
	written = ft_write(1, buf, 7);
	written_or = write(1, buf, 7);
	printf("\norig\tнапечатано:%d, errno:%d\n", written, errno);
	printf("my\tнапечатано:%d, errno:%d\n", written, errno);

	printf("\topen descriptor\n");
	fd = open("./file.txt", O_CREAT | O_RDWR, 416);
	written = write(fd, buf, 4);
	printf("orig\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);
	
	fd = open("./file.txt", O_CREAT | O_RDWR, 416);
	written = ft_write(fd, buf, 4);
	printf("my\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);

	printf("\twrong fd\n");
	fd = open("./file_not_exist", O_RDWR);
	written = write(fd, buf, 4);
	printf("orig\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);
	errno = 0;
	
	fd = open("./file_not_exist", O_RDWR);
	written = ft_write(fd, buf, 4);
	printf("my\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);
	errno = 0;

	printf("--=== ft_read ===---\n");
	char text[10];
	int readed;

	printf("\tВведи 5 символов:\n");
	readed = read(0, text, 5);
	printf("\n text:%s, прочитано:%d, errno:%d\n", text, readed, errno);

	printf("\n");
	printf("\topen descriptor\n");
	fd = open("./file.txt", O_RDONLY);
	readed = read(fd, text, 2);
	printf("orig\ttext:%s, прочитано:%d, errno:%d\n", text, readed, errno);
	close(fd);

	fd = open("./file.txt", O_RDONLY);
	readed = ft_read(fd, text, 2);
	printf("my\ttext:%s, прочитано:%d, errno:%d\n", text, readed, errno);
	close (fd);

	printf("\twrong fd\n");
	fd = open("./file_not_exist", O_RDWR);
	readed = read(fd, text, 2);
	printf("orig\ttext:%s, прочитано:%d, errno:%d\n", text, readed, errno);
	close(fd);
	errno = 0;

	fd = open("./file_not_exist", O_RDWR);
	readed = ft_read(fd, text, 2);
	printf("my\ttext:%s, прочитано:%d, errno:%d\n", text, readed, errno);
	close (fd);
	errno = 0;

	printf("--=== ft_strdup ===---\n");
	printf("empty\n\torig:\t%s \n\tmy:\t%s \nlong\n\torig:\t%s \n\tmy:\t%s \nregular\n\torig:\t%s\n\tmy:\t%s\n", 
	strdup(empty), ft_strdup(empty), 
	strdup(strlong), ft_strdup(strlong),
	strdup(str), ft_strdup(str));
	return (0);
}