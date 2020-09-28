#include <cstdint>
#include <cstdio>

class DynamicInterface {
public:
  virtual void tick(uint64_t n) = 0;
  virtual uint64_t getvalue() = 0;
};

class DynamicImplementation final: public DynamicInterface {
   uint64_t counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  virtual void tick(uint64_t n) {
    counter += n;
  }

  virtual uint64_t getvalue() {
    return counter;
  }
};

const unsigned N = 40000;

//void run_dynamic(DynamicInterface* obj) {
void run_dynamic(DynamicImplementation* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
		asm("");
    }
  }
}

template <typename Implementation>
class CRTPInterface {
public:
  void tick(uint64_t n) {
    impl().tick(n);
  }

  uint64_t getvalue() {
    return impl().getvalue();
  }
private:
  Implementation& impl() {
    return *static_cast<Implementation*>(this);
  }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
  uint64_t counter;
public:
  CRTPImplementation()
    : counter(0) {
  }

  void tick(uint64_t n) {
    counter += n;
  }

  uint64_t getvalue() {
    return counter;
  }
};

template <typename Implementation>
void run_crtp(CRTPInterface<Implementation>* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
		asm("");
    }
  }
}

void static_bench() {
	CRTPInterface<CRTPImplementation>* f = new CRTPImplementation();
	run_crtp(f);
}

void dynamic_bench() {
	//DynamicInterface* f = new DynamicImplementation();
	DynamicImplementation* f = new DynamicImplementation();
	run_dynamic(f);
}

int main(int argc, char* argv[]) {
	if(argc < 2) return 1;
	switch(argv[1][0]) {
	case 'd':
		printf("Analyzing virtual;\n");
		dynamic_bench();
		break;
	case 's':
		printf("Analyzing ctrp;\n");
		static_bench();
		break;
	default:
		return -1;
	}
}
