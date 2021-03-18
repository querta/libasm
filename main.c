/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:37:18 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/18 17:26:59 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

int main()
{
	char *src = "abcdefjh";
	char dst[9];	

	printf("ft_strlen %zu", ft_strlen("abcd12"));
	printf("\nft_strcpy=%s", ft_strcpy(dst, src));
	
	char *str1 = "йййй"; // й - 208
	char *str2 = "ааааа";
	char *str3 = "zzzz";
	char *str4 = "aaaa";
	char *nums1 = "1234";
	char *nums2 = "4321";
	printf("\n");
	printf("\nft_strcmp: %d:%d, %d:%d, %d:%d", strcmp(str1, str2), ft_strcmp(str1, str2), strcmp(nums1, nums2), ft_strcmp(nums1, nums2), strcmp(nums2, nums1), ft_strcmp(nums2, nums1));
	printf("\ncmptest\n %s:%s %d:%d \n %s:%s %d:%d \n %s:%s %d:%d \n %s:%s %d:%d \n %s:%s %d:%d \n %s:%s %d:%d \n",
		str1, str2, strcmp(str1, str2), ft_strcmp(str1, str2),
		str1, nums1, strcmp(str1, nums1), ft_strcmp(str1, nums1),
		nums2, str2, strcmp(nums2, str2), ft_strcmp(nums2, str2),
		str3, str4, strcmp(str3, str4), ft_strcmp(str3, str4),
		nums1, str3, strcmp(nums1, str3), ft_strcmp(nums1, str3),
		nums1, nums2, strcmp(nums1, nums2), ft_strcmp(nums1, nums2)
		);
	printf("\n");
	// ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
	// int fd;
	// int fd2;
	// char *buf = "slovo";
	// int written;
	// int written2;


	// // fd = open("./file2", O_RDWR);
	// // fd = open("./file", O_CREAT | O_RDONLY);
	// fd = open("./file.txt", O_CREAT | O_RDWR, 416);
	// fd2 = open("./file2.txt", O_CREAT | O_RDWR, 416);
	// // if (fd == -1)
	// // {
	// // 	printf("error\n: %d\n", errno);
	// // 	return (0);
	// // }

	// written = ft_write(fd, buf, 4);
	// printf("\n WRITE:\n%u байтов записано в файл\n", written);
	// printf("error: %d\n", errno);
	// written2 = write(fd2, buf, 4);
	// printf("\n WRITE:\n%u байтов записано в файл\n", written2);
	// printf("orig error: %d\n", errno);

	// printf("\n \n READ\n");
	// close(fd);
	// close(fd2);

	// fd = open("./file.txt", O_RDONLY);
	// fd2 = open("./file2.txt", O_RDONLY);
	int fd;
	int written;
	char *buf = "slovo";

	fd = open("./file.txt", O_CREAT | O_RDWR, 416);
	written = write(fd, buf, 4);
	printf("orig\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);
	
	fd = open("./file.txt", O_CREAT | O_RDWR, 416);
	written = ft_write(fd, buf, 4);
	printf("my\tзаписано:%d, errno:%d\n", written, errno);
	close(fd);



	char text[4];
	int readed;

	fd = open("./file.txt", O_RDONLY);
	readed = read(fd, text, 2);
	printf("orig\ttext:%s, rb:%d, errno:%d\n", text, readed, errno);
	close(fd);

	fd = open("./file.txt", O_RDONLY);
	readed = ft_read(fd, text, 2);
	printf("my\ttext:%s, rb:%d, errno:%d\n", text, readed, errno);
	close (fd);

	char *strdupsrc = "aaaaaaa";
	char *strdupdst = ft_strdup(strdupsrc);
	printf("%s", strdupdst);
	printf("|\n");
	return (0);
}