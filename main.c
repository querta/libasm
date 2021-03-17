/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:37:18 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/17 19:30:00 by mmonte           ###   ########.fr       */
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
	printf("\nft_strcmp:\n й:1 %d:%d,\n 1:4 %d:%d,\n 4:1 %d:%d,\n 1:1 %d:%d\n", strcmp("йййй", "1234"), ft_strcmp("йййй", "1234"), strcmp("1234", "4321"), ft_strcmp("1234", "4321"), strcmp("4321", "1234"), ft_strcmp("4321", "1234"), strcmp("1234", "1234"), ft_strcmp("1234", "1234"));
	printf("\nft_strcmp: %d:%d", strcmp("", "aaaaa"), ft_strcmp("", "aaaa"));
	printf("\n");
	return (0);
}