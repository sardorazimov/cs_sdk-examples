class VMTHook {
private:
    void** vtable;
public:
    VMTHook(void* base) {
        vtable = *(void***)base;
    }

    template<typename T>
    void Hook(int index, T hook, T* original) {
        *original = (T)vtable[index];
        vtable[index] = (void*)hook;
    }
};
