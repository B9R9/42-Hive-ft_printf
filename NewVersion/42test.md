FAILED TESTS:\n
# TEST NUMBER (TYPE OF ARG)
  INSTRUCTION();
  1. your function ft_printf
  2. unix function printf
     (returned value) -->written on stdout<--

# 0069 (NULL)
  ft_printf("@moulitest: %s", NULL);
includes/projects/ft_printf/ft_printf_main.sh: line 206: printf: @moulitest: includes/projects/ft_printf/ft_printf_main.sh: line 159:  6015 Segmentation fault: 11  ./tmp/ft_printf_s sN "@moulitest: %s" ""$: invalid number
  1. (    0) -->@moulitest: includes/projects/ft_printf/ft_printf_main.sh: line 159:  6015 Segmentation fault: 11  ./tmp/ft_printf_s sN "@moulitest: %s" "NULL"$<--
  2. (   18) -->@moulitest: (null)<--

# 0071 (NULL)
  ft_printf("%s %s", NULL, string);
includes/projects/ft_printf/ft_printf_main.sh: line 206: printf: includes/projects/ft_printf/ft_printf_main.sh: line 159:  6101 Segmentation fault: 11  ./tmp/ft_printf_s sN "%s %s" "" "string"$: invalid number
  1. (    0) -->includes/projects/ft_printf/ft_printf_main.sh: line 159:  6101 Segmentation fault: 11  ./tmp/ft_printf_s sN "%s %s" "NULL" "string"$<--
  2. (   13) -->(null) string<--

# 0104 (int)
  ft_printf("% d", -42);
  1. (    4) --> -42<--
  2. (    3) -->-42<--

# 0106 (int)
  ft_printf("%+d", -42);
  1. (    4) -->+-42<--
  2. (    3) -->-42<--

# 0107 (int)
  ft_printf("%+d", 0);
  1. (    1) -->0<--
  2. (    2) -->+0<--

# 0108 (int)
  ft_printf("%+d", 4242424242424242424242);
  1. (    3) -->+-1<--
  2. (    2) -->-1<--

# 0109 (int)
  ft_printf("% +d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0111 (int)
  ft_printf("%+ d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0113 (int)
  ft_printf("%  +d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0115 (int)
  ft_printf("%+  d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0117 (int)
  ft_printf("% ++d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0119 (int)
  ft_printf("%++ d", 42);
  1. (    2) -->42<--
  2. (    3) -->+42<--

# 0125 (int)
  ft_printf("%0+5d", 42);
  1. (    6) -->+00042<--
  2. (    5) -->+0042<--
----------------TO BE CONTINUE
# 0127 (int)
  ft_printf("%05d", -42);
  1. (    5) -->00-42<--
  2. (    5) -->-0042<--

# 0128 (int)
  ft_printf("%0+5d", -42);
  1. (    6) -->+00-42<--
  2. (    5) -->-0042<--

# 0135 (short)
  ft_printf("%hd", 32768);
  1. (   20) -->18446744073709518848<--
  2. (    6) -->-32768<--

# 0138 (signed char)
  ft_printf("%hhd", 128);
  1. (    5) -->--128<--
  2. (    4) -->-128<--

# 0139 (signed char)
  ft_printf("%hhd", -128);
  1. (    5) -->--128<--
  2. (    4) -->-128<--

# 0146 (long long)
  ft_printf("%lld", -9223372036854775808);
  1. (    1) -->-<--
  2. (   20) -->-9223372036854775808<--

# 0156 (int)
  ft_printf("%-10.5d", 4242);
  1. (   10) -->4242      <--
  2. (   10) -->04242     <--

# 0158 (int)
  ft_printf("%+10.5d", 4242);
  1. (   10) -->+    04242<--
  2. (   10) -->    +04242<--

# 0159 (int)
  ft_printf("%-+10.5d", 4242);
  1. (   10) -->4242      <--
  2. (   10) -->+04242    <--

# 0160 (int)
  ft_printf("%03.2d", 0);
  1. (    3) -->00 <--
  2. (    3) --> 00<--

# 0161 (int)
  ft_printf("%03.2d", 1);
  1. (    3) -->001<--
  2. (    3) --> 01<--

# 0162 (int)
  ft_printf("%03.2d", -1);
  1. (    3) -->0-1<--
  2. (    3) -->-01<--

# 0163 (int)
  ft_printf("@moulitest: %.10d", -42);
  1. (   22) -->@moulitest: 0000000-42<--
  2. (   23) -->@moulitest: -0000000042<--

# 0165 (int)
  ft_printf("@moulitest: %.d %.0d", 0, 0);
  1. (   15) -->@moulitest:    <--
  2. (   13) -->@moulitest:  <--

# 0177 (unsigned int)
  ft_printf("%+u", 4294967295);
  1. (   11) -->+4294967295<--
  2. (   10) -->4294967295<--

