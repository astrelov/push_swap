cmake_minimum_required(VERSION 3.9)
project(ft_push_swap C)

set(CMAKE_C_STANDARD 99)

set(LIBFT
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
        src/operations/s.c
        src/list/lst_splice.c
        src/helpers/helpers2.c
        src/operations/p.c
        src/operations/r.c
        src/operations/rr.c
        src/helpers/finders.c src/helpers/shared_ps_checker.c)

set(CHECKER
        src/checker.c
        src/operations/p.c
        src/operations/r.c
        )

set(PUSH_SWAP
        src/push_swap.c src/helpers/moving_nbrs_to_b.c)

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