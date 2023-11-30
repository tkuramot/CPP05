CXX      := c++
CXXFLAGS := -g -MMD -MP -Wall -Wextra -Werror -std=c++98
DFLAGS   := -fsanitize=address -fsanitize=bounds
INCLUDE  := -I includes
NAME     := a.out
SRCDIR   := srcs
SRCS     := \
        srcs/Form.cpp \
        srcs/Bureaucrat.cpp \
        srcs/main.cpp
OBJDIR   := objs
OBJS     := $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS  := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CXX) -o $@ $^ $(INCLUDE) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make DEBUG=1

cppfile:
	find srcs -name "*.cpp" | sed 's/\.\///g' | awk '{print "\t"$$0" \\"}' | sed '$$s/ \\//'

-include $(DEPENDS)

.PHONY: all clean fclean re
