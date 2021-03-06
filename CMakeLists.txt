cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(LIBFT
        libft/ft_printf/includes/ft_printf.h
        libft/ft_printf/src/ft_printf.c
        libft/ft_printf/src/parse/flags.c
        libft/ft_printf/src/parse/parse.c
        libft/ft_printf/src/parse/width.c
        libft/ft_printf/src/parse/precision.c
        libft/ft_printf/src/parse/length.c
        libft/ft_printf/src/handle/handle.c
        libft/ft_printf/src/handle/number.c
        libft/ft_printf/src/handle/char.c
        libft/ft_printf/src/helpers/buffer.c
        libft/ft_printf/src/handle/wchar.c
        libft/ft_printf/src/handle/string.c
        libft/ft_printf/src/handle/pointer.c
        libft/ft_printf/src/handle/wstring.c
        libft/ft_printf/src/handle/integer/integer.c
        libft/ft_printf/src/handle/integer/octal.c
        libft/ft_printf/src/handle/integer/hexademical.c
        libft/ft_printf/src/handle/integer/decimal.c
        libft/ft_printf/src/helpers/push_chars.c
        libft/ft_printf/src/handle/invalid_specifier.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_d_bblsort.c
        libft/ft_d_minind.c
        libft/ft_d_sqrt.c
        libft/ft_errmsg.c
        libft/ft_gnl.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lf_pow.c
        libft/ft_ll_fact.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strpbrk.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtoupp.c
        libft/ft_strtolow.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        )

set(SHARE
        includes/push_swap.h
        src/list/lst_new_node.c
        src/list/lst_push.c
        src/list/lst_pop.c
        src/list/lst_create.c
        src/list/lst_push_head.c
        src/list/lst_is_sorted.c
        src/list/lst_shift.c
        src/list/lst_splice.c
        src/operations/s.c
        src/operations/p.c
        src/operations/r.c
        src/operations/rr.c
        src/movers/mr_cleaner.c
        src/movers/shared_ps_checker.c
        )

set(CHECKER
        src/checker.c
        )

set(PUSH_SWAP
        src/push_swap.c
        src/movers/moving_nbrs_to_b.c
        src/movers/moving_nbrs_to_a.c
        src/movers/finders_for_moving_to_a.c
        src/movers/moving_nbrs_to_a_2.c
        src/operations/p_s_op_handler.c
        src/movers/three_nbrs_in_stack_a.c
        src/movers/finders.c
        )

add_executable(checker
        ${CHECKER}
        ${SHARE}
        ${LIBFT}
        )

add_executable(push_swap
        ${PUSH_SWAP}
        ${SHARE}
        ${LIBFT}
        )