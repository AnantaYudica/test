#ifndef TEST_OUT_FILE_H_
#define TEST_OUT_FILE_H_

#include "Interface.h"
#include "Standard.h"
#include "file/Base.h"

#include <cstdio>
#include <cstdarg>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

namespace test
{
namespace out
{

template<typename TChar, 
    std::size_t MinimumBuffer = test::out::file::DefaultMinimumBuffer,
    std::size_t MaximumBuffer = test::out::file::DefaultMaximumBuffer>
class File : 
    private test::out::file::Base<TChar, MinimumBuffer, MaximumBuffer>,
    public test::out::Interface<TChar>
{
private:
    typedef test::out::file::Base<TChar, MinimumBuffer, 
        MaximumBuffer> BaseType;
public:
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::ModeType ModeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::StatusIntegerValueType StatusIntegerValueType;
public:
public:
    static constexpr ModeType mode_undefined = BaseType::mode_undefined;
    static constexpr ModeType mode_write = BaseType::mode_write;
    static constexpr ModeType mode_append = BaseType::mode_append;
public:
    static constexpr SizeType filename_maximum_size = 
        BaseType::filename_maximum_size; 
public:
    File();
    File(const char * filename, const ModeType& mode);
    File(const char * filename, const ModeType& mode, 
        const SizeType& maximum_size);
public:
    virtual ~File();
public:
    File(const File<TChar, MinimumBuffer, MaximumBuffer> &) = delete;
    File(File<TChar, MinimumBuffer, MaximumBuffer> &&) = delete;
public:
    File<TChar, MinimumBuffer, MaximumBuffer>& 
        operator=(const File<TChar, MinimumBuffer, MaximumBuffer>&) = delete;
    File<TChar, MinimumBuffer, MaximumBuffer>& 
        operator=(File<TChar, MinimumBuffer, MaximumBuffer>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode) override;
private:
    using BaseType::PrintGuard;
protected:
    using BaseType::GetStatus;
private:
    using BaseType::_Open;
    using BaseType::_Close;
    using BaseType::_Size;
    using BaseType::_CheckSize;
    using BaseType::_TriggerMaximumSize;
    using BaseType::_SetFilename;
    using BaseType::_Initialize;
protected:
    using BaseType::Initialize;
public:
    using BaseType::Mode;
public:
    using BaseType::Size;
public:
    using BaseType::MaximumSize;
public:
    using BaseType::Filename;
private:
    using BaseType::GetFile;
    using BaseType::SetSize;
    using BaseType::GetSize;
    using BaseType::SetTemporary;
    using BaseType::GetTemporary;
protected:
    SizeType Puts(const TChar * cstr, const SizeType& size) override;
    SizeType Puts(const TChar * cstr) override;
    template<std::size_t S>
    SizeType Puts(const TChar(&cstr)[S]);
    SizeType Puts(const test::CString<TChar>& cstr) override;
    SizeType Puts(const test::CString<const TChar>& cstr) override;
protected:
    using BaseType::Buffer;
protected:
    bool IsGood() const override;
    bool IsBad() const override;
protected:
    using BaseType::GetBadCode;
protected:
    using BaseType::IsStandard;
};

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
class File<char, MinimumBuffer, MaximumBuffer> : 
    private test::out::file::Base<char, MinimumBuffer, MaximumBuffer>,
    public test::out::Interface<char>
{
private:
    typedef test::out::file::Base<char, MinimumBuffer, 
        MaximumBuffer> BaseType;
public:
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::ModeType ModeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::StatusIntegerValueType StatusIntegerValueType;
public:
public:
    static constexpr ModeType mode_undefined = BaseType::mode_undefined;
    static constexpr ModeType mode_write = BaseType::mode_write;
    static constexpr ModeType mode_append = BaseType::mode_append;
public:
    static constexpr SizeType filename_maximum_size = 
        BaseType::filename_maximum_size; 
public:
    File();
    File(const char * filename, const ModeType& mode);
    File(const char * filename, const ModeType& mode, 
        const SizeType& maximum_size);
public:
    virtual ~File();
public:
    File(const File<char, MinimumBuffer, MaximumBuffer> &) = delete;
    File(File<char, MinimumBuffer, MaximumBuffer> &&) = delete;
public:
    File<char, MinimumBuffer, MaximumBuffer>& 
        operator=(const File<char, MinimumBuffer, MaximumBuffer>&) = delete;
    File<char, MinimumBuffer, MaximumBuffer>& 
        operator=(File<char, MinimumBuffer, MaximumBuffer>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode) override;
private:
    using BaseType::PrintGuard;
protected:
    using BaseType::GetStatus;
private:
    using BaseType::_Open;
    using BaseType::_Close;
    using BaseType::_Size;
    using BaseType::_CheckSize;
    using BaseType::_TriggerMaximumSize;
    using BaseType::_SetFilename;
    using BaseType::_Initialize;
protected:
    using BaseType::Initialize;
public:
    using BaseType::Mode;
public:
    using BaseType::Size;
public:
    using BaseType::MaximumSize;
public:
    using BaseType::Filename;
private:
    using BaseType::GetFile;
    using BaseType::SetSize;
    using BaseType::GetSize;
    using BaseType::SetTemporary;
    using BaseType::GetTemporary;
protected:
    SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
protected:
    SizeType Puts(const char * cstr, const SizeType& size) override;
    SizeType Puts(const char * cstr) override;
    template<std::size_t S>
    SizeType Puts(const char(&cstr)[S]);
    SizeType Puts(const test::CString<char>& cstr) override;
    SizeType Puts(const test::CString<const char>& cstr) override;
protected:
    using BaseType::Buffer;
protected:
    bool IsGood() const override;
    bool IsBad() const override;
protected:
    using BaseType::GetBadCode;
protected:
    using BaseType::IsStandard;
};

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
class File<wchar_t, MinimumBuffer, MaximumBuffer> : 
    private test::out::file::Base<wchar_t, MinimumBuffer, MaximumBuffer>,
    public test::out::Interface<wchar_t>
{
private:
    typedef test::out::file::Base<wchar_t, MinimumBuffer, 
        MaximumBuffer> BaseType;
public:
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::ModeType ModeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::StatusIntegerValueType StatusIntegerValueType;
public:
public:
    static constexpr ModeType mode_undefined = BaseType::mode_undefined;
    static constexpr ModeType mode_write = BaseType::mode_write;
    static constexpr ModeType mode_append = BaseType::mode_append;
public:
    static constexpr SizeType filename_maximum_size = 
        BaseType::filename_maximum_size; 
public:
    File();
    File(const char * filename, const ModeType& mode);
    File(const char * filename, const ModeType& mode, 
        const SizeType& maximum_size);
public:
    virtual ~File();
public:
    File(const File<wchar_t, MinimumBuffer, MaximumBuffer> &) = delete;
    File(File<wchar_t, MinimumBuffer, MaximumBuffer> &&) = delete;
public:
    File<wchar_t, MinimumBuffer, MaximumBuffer>& 
        operator=(const File<wchar_t, MinimumBuffer, MaximumBuffer>&) = delete;
    File<wchar_t, MinimumBuffer, MaximumBuffer>& 
        operator=(File<wchar_t, MinimumBuffer, MaximumBuffer>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode) override;
private:
    using BaseType::PrintGuard;
protected:
    using BaseType::GetStatus;
private:
    using BaseType::_Open;
    using BaseType::_Close;
    using BaseType::_Size;
    using BaseType::_CheckSize;
    using BaseType::_TriggerMaximumSize;
    using BaseType::_SetFilename;
    using BaseType::_Initialize;
protected:
    using BaseType::Initialize;
public:
    using BaseType::Mode;
public:
    using BaseType::Size;
public:
    using BaseType::MaximumSize;
public:
    using BaseType::Filename;
private:
    using BaseType::GetFile;
    using BaseType::SetSize;
    using BaseType::GetSize;
    using BaseType::SetTemporary;
    using BaseType::GetTemporary;
protected:
    SizeType VPrint(const wchar_t * format, va_list var_args) override;
    SizeType Print(const wchar_t * format, ...) override;
protected:
    SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    SizeType Puts(const wchar_t * cstr) override;
    template<std::size_t S>
    SizeType Puts(const wchar_t(&cstr)[S]);
    SizeType Puts(const test::CString<wchar_t>& cstr) override;
    SizeType Puts(const test::CString<const wchar_t>& cstr) override;
protected:
    using BaseType::Buffer;
protected:
    bool IsGood() const override;
    bool IsBad() const override;
protected:
    using BaseType::GetBadCode;
protected:
    using BaseType::IsStandard;
};

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<TChar, MinimumBuffer, MaximumBuffer>::File() :
    BaseType()
{}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<TChar, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode) :
        BaseType(filename, mode)
{}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<TChar, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode, const SizeType& maximum_size) :
        BaseType(filename, mode, maximum_size)
{}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<TChar, MinimumBuffer, MaximumBuffer>::~File()
{}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<TChar, MinimumBuffer, MaximumBuffer>::
    OnMaximumSize(test::CString<char>,
        test::CString<char>&, ModeType&)
{
    return false;
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<TChar, MinimumBuffer, MaximumBuffer>::SizeType
File<TChar, MinimumBuffer, MaximumBuffer>::
    Puts(const TChar * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<TChar, MinimumBuffer, MaximumBuffer>::SizeType
File<TChar, MinimumBuffer, MaximumBuffer>::Puts(const TChar * cstr)
{
    const auto size = test::cstr::Length<TChar>::Value(cstr, MaximumBuffer);
    return Puts(cstr, size);
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<std::size_t S>
typename File<TChar, MinimumBuffer, MaximumBuffer>::SizeType
File<TChar, MinimumBuffer, MaximumBuffer>::Puts(const TChar(&cstr)[S])
{
    return Puts(cstr, S - 1);
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<TChar, MinimumBuffer, MaximumBuffer>::SizeType
File<TChar, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<TChar>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<TChar, MinimumBuffer, MaximumBuffer>::SizeType 
File<TChar, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<const TChar>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<TChar, MinimumBuffer, MaximumBuffer>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TChar, std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<TChar, MinimumBuffer, MaximumBuffer>::IsBad() const
{
    return BaseType::IsBad();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<char, MinimumBuffer, MaximumBuffer>::File() :
    BaseType()
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<char, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode) :
        BaseType(filename, mode)
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<char, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode, const SizeType& maximum_size) :
        BaseType(filename, mode, maximum_size)
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<char, MinimumBuffer, MaximumBuffer>::~File()
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<char, MinimumBuffer, MaximumBuffer>::
    OnMaximumSize(test::CString<char>,
        test::CString<char>&, ModeType&)
{
    return false;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::VPrint(const char * format, 
    va_list var_args)
{
    if (!Initialize()) return 0;

    auto guard = PrintGuard();
    if(!guard) return 0;
    
    auto& status = GetStatus();
    char * buffer = new char[MinimumBuffer];
    int buffer_size = test::out::VSPrint<char>(buffer, MinimumBuffer, format,
        var_args);
    if (buffer_size < 0)
    {
        delete[] buffer;
        status.Bad(StatusType::print_buffer_failed);
        SetTemporary(std::move(test::CString<char>("", 0)));
        return 0;
    } 
    else if ((SizeType)buffer_size >= MinimumBuffer && 
        (SizeType)buffer_size < MaximumBuffer)
    {
        delete[] buffer;
        buffer = new char[buffer_size + 1];
        test::out::VSPrint<char>(buffer, buffer_size + 1, format, var_args);
    }
    else if ((SizeType)buffer_size >= MaximumBuffer)
    {
        delete[] buffer;
        buffer = nullptr;
        status.Bad(StatusType::print_buffer_overflow);
        SetTemporary(std::move(test::CString<char>("", 0)));
        return 0;
    }

    if (buffer_size > 0)
        SetTemporary(std::move(test::CString<char>(buffer, buffer_size)));
    else
        SetTemporary(std::move(test::CString<char>("", 0)));

    if (buffer != nullptr) delete[] buffer;

    if (!_CheckSize(buffer_size)) return 0;
    if (!status.IsStandardOutput()) SetSize(GetSize() + buffer_size);

    int ret_puts = test::out::FPuts<char>(GetTemporary(), GetFile());
    fflush(GetFile());

    if (ret_puts < 0)
    {
        status.Bad(StatusType::print_output_failed);
        return 0;
    }

    return buffer_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::Print(const char * format, ...)
{
    
    va_list var_args;
    va_start(var_args, format);
    
    SizeType size = VPrint(format, var_args);

    va_end(var_args);

    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::
    Puts(const char * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::Puts(const char * cstr)
{
    const auto size = test::cstr::Length<char>::Value(cstr, MaximumBuffer);
    return Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<std::size_t S>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::Puts(const char(&cstr)[S])
{
    return Puts(cstr, S - 1);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType
File<char, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<char>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<char, MinimumBuffer, MaximumBuffer>::SizeType 
File<char, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<const char>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<char, MinimumBuffer, MaximumBuffer>::IsGood() const
{
    return BaseType::IsGood();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<char, MinimumBuffer, MaximumBuffer>::IsBad() const
{
    return BaseType::IsBad();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<wchar_t, MinimumBuffer, MaximumBuffer>::File() :
    BaseType()
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<wchar_t, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode) :
        BaseType(filename, mode)
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<wchar_t, MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode, const SizeType& maximum_size) :
        BaseType(filename, mode, maximum_size)
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<wchar_t, MinimumBuffer, MaximumBuffer>::~File()
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<wchar_t, MinimumBuffer, MaximumBuffer>::
    OnMaximumSize(test::CString<char>, test::CString<char>&, ModeType&)
{
    return false;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::VPrint(const wchar_t * format, 
    va_list var_args)
{
    if (!Initialize()) return 0;

    auto guard = PrintGuard();
    if(!guard) return 0;
    
    auto& status = GetStatus();
    wchar_t * buffer = new wchar_t[MinimumBuffer];
    int buffer_size = test::out::VSPrint<wchar_t>(buffer, MinimumBuffer, 
        format, var_args);
    if (buffer_size < 0)
    {
        delete[] buffer;
        status.Bad(StatusType::print_buffer_failed);
        SetTemporary(std::move(test::CString<wchar_t>(L"", 0)));
        return 0;
    } 
    else if ((SizeType)buffer_size >= MinimumBuffer && 
        (SizeType)buffer_size < MaximumBuffer)
    {
        delete[] buffer;
        buffer = new wchar_t[buffer_size + 1];
        test::out::VSPrint<wchar_t>(buffer, buffer_size + 1, format, var_args);
    }
    else if ((SizeType)buffer_size >= MaximumBuffer)
    {
        delete[] buffer;
        buffer = nullptr;
        status.Bad(StatusType::print_buffer_overflow);
        SetTemporary(std::move(test::CString<wchar_t>(L"", 0)));
        return 0;
    }

    if (buffer_size > 0)
        SetTemporary(std::move(test::CString<wchar_t>(buffer, buffer_size)));
    else
        SetTemporary(std::move(test::CString<wchar_t>(L"", 0)));

    if (buffer != nullptr) delete[] buffer;

    if (!_CheckSize(buffer_size)) return 0;
    if (!status.IsStandardOutput()) SetSize(GetSize() + buffer_size);

    int ret_puts = test::out::FPuts<wchar_t>(GetTemporary(), GetFile());
    fflush(GetFile());

    if (ret_puts < 0)
    {
        status.Bad(StatusType::print_output_failed);
        return 0;
    }

    return buffer_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::Print(const wchar_t * format, ...)
{
    
    va_list var_args;
    va_start(var_args, format);
    
    SizeType size = VPrint(format, var_args);

    va_end(var_args);

    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::
    Puts(const wchar_t * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::Puts(const wchar_t * cstr)
{
    const auto size = test::cstr::Length<wchar_t>::Value(cstr, MaximumBuffer);
    return Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<std::size_t S>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::Puts(const wchar_t(&cstr)[S])
{
    return Puts(cstr, S - 1);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType
File<wchar_t, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<wchar_t>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<wchar_t, MinimumBuffer, MaximumBuffer>::SizeType 
File<wchar_t, MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<const wchar_t>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<wchar_t, MinimumBuffer, MaximumBuffer>::IsGood() const
{
    return BaseType::IsGood();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<wchar_t, MinimumBuffer, MaximumBuffer>::IsBad() const
{
    return BaseType::IsBad();
}

} //!out

} //!test

#endif //!TEST_OUT_FILE_H_
