/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:17:11 by cchen             #+#    #+#             */
/*   Updated: 2022/05/03 13:36:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_basic(); // test ok 
	test_lengths(); //  test ok
	test_flags(); // test ok
	test_precision(); //test ok
	test_widths(); //test ok
	test_wildcards(); // test ok
	test_more(); // test ok
	return (0);
}
