GIT = git
ADD = $(GIT) add .
COMMIT = $(GIT) commit -m "exceptions"
PUSH = $(GIT) push

all:
	$(ADD) && $(COMMIT) && $(PUSH)
