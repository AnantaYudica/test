#ifndef TEST_OUT_FILE_H_
#define TEST_OUT_FILE_H_

#include "../CString.h"
#include "../cstr/Length.h"
#include "file/Status.h"
#include "file/Base.h"
#include "Interface.h"
#include "Standard.h"

#include <cstdio>
#include <cstddef>
#include <cstdarg>
#include <utility>
#include <cstdint>

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

template<std::size_t MinimumBuffer = 512,
    std::size_t MaximumBuffer = 65535>
class File : 
    private test::out::file::Base,
    public test::out::Interface<char>,
    public test::out::Interface<wchar_t>
{
public:
    static_assert(MinimumBuffer != 0, "Minimum Buffer cannot zero");
    static_assert(MinimumBuffer <= MaximumBuffer, 
        "Minimum Buffer cannot more then Maximum Buffer");
private:
    typedef test::out::file::Base BaseType;
public:
    typedef std::size_t SizeType;
    typedef std::uint8_t ModeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename StatusType::ValueType StatusValueType;
public:
    enum : ModeType
    {
        mode_undefined = 0,
        mode_write = 1,
        mode_append = 2
    };
public:
    static constexpr SizeType filename_maximum_size = FILENAME_MAX; 
private:
    static bool _Open(FILE *& file, test::CString<char>& filename,
        const char * mode);
    static bool _Size(test::CString<char>& filename, 
        SizeType& size, StatusType& status);
private:
    ModeType m_mode;
    FILE * m_file;
    test::CString<char> m_filename;
    test::CString<char> m_char_tmp;
    test::CString<wchar_t> m_wchar_tmp;
    SizeType m_size;
    const SizeType m_maximum_size;
public:
    File();
    File(const char * filename, const ModeType& mode);
    File(const char * filename, const ModeType& mode, 
        const SizeType& maximum_size);
public:
    virtual ~File();
public:
    File(const File<MinimumBuffer, MaximumBuffer> &) = delete;
    File(File<MinimumBuffer, MaximumBuffer> &&) = delete;
public:
    File<MinimumBuffer, MaximumBuffer>& 
        operator=(const File<MinimumBuffer, MaximumBuffer>&) = delete;
    File<MinimumBuffer, MaximumBuffer>& 
        operator=(File<MinimumBuffer, MaximumBuffer>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode);
private:
    bool _Open();
    bool _Close();
    bool _Size();
    bool _CheckSize(const SizeType& buffer_size);
    bool _TriggerMaximumSize();
    bool _SetFilename(const char * filename);
    bool _SetFilename(test::CString<char>& filename);
    bool _Initialize();
protected:
    bool Initialize();
public:
    ModeType Mode() const;
public:
    SizeType Size() const;
public:
    SizeType MaximumSize() const;
public:
    test::CString<char> Filename() const;
protected:
    SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
    SizeType VPrint(const wchar_t * format, va_list var_args) override;
    SizeType Print(const wchar_t * format, ...) override;
protected:
    SizeType Puts(const char * cstr, const SizeType& size) override;
    SizeType Puts(const char * cstr) override;
    template<std::size_t S>
    SizeType Puts(const char(&cstr)[S]);
    SizeType Puts(const test::CString<char>& cstr) override;
    SizeType Puts(const test::CString<const char>& cstr) override;
    SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    SizeType Puts(const wchar_t * cstr) override;
    template<std::size_t S>
    SizeType Puts(const wchar_t(&cstr)[S]);
    SizeType Puts(const test::CString<wchar_t>& cstr) override;
    SizeType Puts(const test::CString<const wchar_t>& cstr) override;
protected:
    template<typename TChar, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    test::CString<TChar> Buffer() const;
    template<typename TChar, typename std::enable_if<
        std::is_same<TChar, wchar_t>::value, int>::type = 1>
    test::CString<TChar> Buffer() const;
protected:
    bool IsGood() const override;
    bool IsBad() const override;
    StatusValueType GetBadCode() const;
protected:
    bool IsStandard() const;
};

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    _Open(FILE *& file, test::CString<char>& filename, const char * mode)
{
#if (defined(_MSC_BUILD) && !defined(_CRT_SECURE_NO_WARNINGS))
    if (fopen_s(&file, *filename, mode) != 0) return false;
#else 
    file = fopen(*filename, mode);
#endif 
    return file != nullptr;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    _Size(test::CString<char>& filename, SizeType& size, StatusType& status)
{
    FILE * read_file = nullptr;
    const auto is_open = _Open(read_file, filename, "r");
    size = 0;
    if (is_open)
    {   
        const auto ret_seek = fseek(read_file, 0, SEEK_END);
        if (ret_seek < 0)
        {
            status.Bad(StatusType::size_file_seek_failed);
        }
        else
        {
            const auto res = ftell(read_file);
            if (res == -1L)
            {
                status.Bad(StatusType::size_file_tell_failed);
            }
            else
                size = res;
            
        }
        const auto is_close = fclose(read_file);
        if (is_close == EOF)
        {
            status.Bad(StatusType::size_file_close_failed);
            size = 0;
            return false;
        }
    }
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<MinimumBuffer, MaximumBuffer>::File() :
    BaseType(StatusType::standard_output),
    m_mode(mode_undefined),
    m_file(stdout),
    m_filename(),
    m_char_tmp(),
    m_wchar_tmp(),
    m_size(0), 
    m_maximum_size(0)
{}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode) :
        BaseType(StatusType::file_output | StatusType::require_initialize),
        m_mode(mode),
        m_file(nullptr),
        m_filename(),
        m_char_tmp(),
        m_wchar_tmp(),
        m_size(0),
        m_maximum_size(MaximumBuffer)
{
    _SetFilename(filename);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<MinimumBuffer, MaximumBuffer>::File(const char * filename, 
    const ModeType& mode, const SizeType& maximum_size) :
        BaseType(StatusType::file_output | StatusType::require_initialize),
        m_mode(mode),
        m_file(nullptr),
        m_filename(),
        m_char_tmp(),
        m_wchar_tmp(),
        m_size(0),
        m_maximum_size(maximum_size)
{
    _SetFilename(filename);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
File<MinimumBuffer, MaximumBuffer>::~File()
{
    if (m_file != nullptr && m_file != stdout)
    {
        fclose(m_file);
        m_file = nullptr;
    }
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    OnMaximumSize(test::CString<char>,
        test::CString<char>&, ModeType&)
{
    return false;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::_Open()
{
    auto& status = GetStatus();
    
    if (m_mode & mode_append)
    {
        
        if (!_Open(m_file, m_filename, "a"))
        {
            status.Bad(StatusType::open_file_failed);
            return false;
        }
    }
    else if (m_mode & mode_write)
    {
        if (!_Open(m_file, m_filename, "w"))
        {
            status.Bad(StatusType::open_file_failed);
            return false;
        }
    }
    else
    {
        status.Bad(StatusType::open_file_mode_undefined);
        return false;
    }
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::_Close()
{
    auto& status = GetStatus();
    
    auto is_close = fclose(m_file);
    if (is_close == EOF)
    {
        status.Bad(StatusType::close_file_failed);
        return false;
    }
    m_file = nullptr;
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::_Size()
{
    auto& status = GetStatus();
    if (m_mode & mode_append)
    {
        SizeType size = 0;
        const auto status_size = _Size(m_filename, size, status);
        
        if (!status_size) return false;
        if (size >= m_maximum_size && !_TriggerMaximumSize()) return false;
        else m_size = size;
    }
    else m_size = 0;
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    _CheckSize(const SizeType& buffer_size)
{
    auto& status = GetStatus();

    const SizeType total_size = buffer_size + m_size;
    if (total_size >= m_maximum_size && !status.IsStandardOutput())
    {
        if (!_Close()) return 0;
        if (!_TriggerMaximumSize()) return 0;
        const SizeType new_total_size = buffer_size + m_size;
        if (new_total_size >= m_maximum_size)
        {
            status.Bad(StatusType::unresolve_size_overflow);
            return false;
        }
        if (!_Open()) return false;
    }
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::_TriggerMaximumSize()
{
    auto& status = GetStatus();

    test::CString<char> new_filename;
    ModeType mode = m_mode;
    if (!OnMaximumSize({m_filename}, new_filename, mode))
    {
        status.Bad(StatusType::size_overflow);
        return false;
    }
    
    if (!_SetFilename(new_filename)) return false;
    m_mode = std::move(mode);
    
    if (m_mode & mode_append)
    { 
        SizeType new_size = 0;
        if (!_Size(m_filename, new_size, status)) return false;
        if (new_size >= m_maximum_size)
        {
            status.Bad(StatusType::unresolve_size_overflow);
            return false;
        }
        m_size = new_size;
    }
    else if (m_mode & mode_write)
    {
        m_size = 0;
    }
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    _SetFilename(const char * filename)
{
    auto& status = GetStatus();
    const SizeType len = test::cstr::Length<char>::Value(filename, 
        filename_maximum_size);
    if (len >= filename_maximum_size)
    {
        status.Bad(StatusType::filename_size_overflow);
        return false;
    }
    m_filename = std::move(test::CString<char>(filename, len));
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::
    _SetFilename(test::CString<char>& filename)
{
    auto& status = GetStatus();
    if (filename.Size() >= filename_maximum_size)
    {
        status.Bad(StatusType::filename_size_overflow);
        return false;
    }
    m_filename = std::move(filename);
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::_Initialize()
{
    auto& status = GetStatus();
    if (status.IsRequire(StatusType::require_initialize))
    {
        auto guard = BaseType::InitializeGuard();
        if (!guard) return false;

        status.Unrequire(StatusType::require_initialize);

        if (status.IsStandardOutput())
        {
            status.Bad(StatusType::initialize_failed);
            return false;
        }
        if (!_Size()) return false;
        if (!_Open()) return false;
    }
    return true;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::Initialize()
{
    auto& status = GetStatus();
    if (status.IsBad()) return false;
    return _Initialize();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::ModeType 
    File<MinimumBuffer, MaximumBuffer>::Mode() const
{
    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return mode_undefined;
    
    pthis->_Initialize();

    auto guard = pthis->BaseType::ModeGuard();
    if (!guard) return mode_undefined;
    return m_mode;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
    File<MinimumBuffer, MaximumBuffer>::Size() const
{
    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return 0;
    
    pthis->_Initialize();

    auto guard = pthis->BaseType::SizeGuard();
    if (!guard) return 0;
    return m_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
    File<MinimumBuffer, MaximumBuffer>::MaximumSize() const
{
    return m_maximum_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
test::CString<char> File<MinimumBuffer, MaximumBuffer>::Filename() const
{
    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return {};
    
    pthis->_Initialize();

    auto guard = pthis->BaseType::FilenameGuard();
    if (!guard) return {};
    return {m_filename};
} 

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::VPrint(const char * format, 
    va_list var_args)
{
    if (!Initialize()) return 0;

    auto guard = BaseType::PrintGuard();
    if(!guard) return 0;
    
    m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));
    
    auto& status = GetStatus();
    char * buffer = new char[MinimumBuffer];
    int buffer_size = test::out::VSPrint<char>(buffer, MinimumBuffer, 
        format, var_args);
    if (buffer_size < 0)
    {
        delete[] buffer;
        status.Bad(StatusType::print_buffer_failed);
        m_char_tmp = std::move(test::CString<char>("", 0));
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
        m_char_tmp = std::move(test::CString<char>("", 0));
        return 0;
    }

    if (buffer_size > 0)
        m_char_tmp = std::move(test::CString<char>(buffer, buffer_size));
    else
        m_char_tmp = std::move(test::CString<char>("", 0));

    if (buffer != nullptr) delete[] buffer;

    if (!_CheckSize(buffer_size)) return 0;
    if (!status.IsStandardOutput()) m_size += buffer_size;

    int ret_puts = test::out::FPuts<char>(*m_char_tmp, m_file);
    fflush(m_file);

    if (ret_puts < 0)
    {
        status.Bad(StatusType::print_output_failed);
        return 0;
    }

    return buffer_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::Print(const char * format, ...)
{
    va_list var_args;
    va_start(var_args, format);
    
    SizeType size = VPrint(format, var_args);

    va_end(var_args);

    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::VPrint(const wchar_t * format, 
    va_list var_args)
{
    if (!Initialize()) return 0;

    auto guard = BaseType::PrintGuard();
    if(!guard) return 0;
    
    m_char_tmp = std::move(test::CString<char>("", 0));
    
    auto& status = GetStatus();
    wchar_t * buffer = new wchar_t[MinimumBuffer];
    int buffer_size = test::out::VSPrint<wchar_t>(buffer, MinimumBuffer, 
        format, var_args);
    if (buffer_size < 0)
    {
        delete[] buffer;
        status.Bad(StatusType::print_buffer_failed);
        m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));
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
        m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));
        return 0;
    }

    if (buffer_size > 0)
        m_wchar_tmp = std::move(test::CString<wchar_t>(buffer, buffer_size));
    else
        m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));

    if (buffer != nullptr) delete[] buffer;

    if (!_CheckSize(buffer_size)) return 0;
    if (!status.IsStandardOutput()) m_size += buffer_size;

    int ret_puts = test::out::FPuts<wchar_t>(*m_wchar_tmp, m_file);
    fflush(m_file);

    if (ret_puts < 0)
    {
        status.Bad(StatusType::print_output_failed);
        return 0;
    }

    return buffer_size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Print(const wchar_t * format, ...)
{
    va_list var_args;
    va_start(var_args, format);
    
    SizeType size = VPrint(format, var_args);

    va_end(var_args);

    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::
    Puts(const char * cstr, const SizeType& size)
{
    if (!Initialize()) return 0;

    auto guard = BaseType::PutsGuard();
    if (!guard) return 0;
    
    m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));

    auto& status = GetStatus();

    if (status.IsBad()) return 0;

    if (size < MaximumBuffer)
        m_char_tmp = std::move(test::CString<char>(cstr, size));
    else
    {
        m_char_tmp = std::move(test::CString<char>("", 0));
        status.Bad(StatusType::puts_buffer_overflow);
        return 0;
    }
    
    if (!_CheckSize(size)) return 0;
    if (!status.IsStandardOutput()) m_size += size;

    int ret_puts = test::out::FPuts<char>(*m_char_tmp, m_file);

    if (ret_puts < 0)
    {
        status.Bad(StatusType::puts_output_failed);
        return 0;
    }
    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::Puts(const char * cstr)
{
    const auto size = test::cstr::Length<char>::Value(cstr, MaximumBuffer);
    return Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<std::size_t S>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::Puts(const char(&cstr)[S])
{
    return Puts(cstr, S - 1);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType
File<MinimumBuffer, MaximumBuffer>::Puts(const test::CString<char>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Puts(const test::CString<const char>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Puts(const wchar_t * cstr, 
    const SizeType& size)
{
    if (!Initialize()) return 0;

    auto guard = BaseType::PutsGuard();
    if (!guard) return 0;
    
    m_char_tmp = std::move(test::CString<char>("", 0));

    auto& status = GetStatus();

    if (status.IsBad()) return 0;

    if (size < MaximumBuffer)
        m_wchar_tmp = std::move(test::CString<wchar_t>(cstr, size));
    else
    {
        m_wchar_tmp = std::move(test::CString<wchar_t>(L"", 0));
        status.Bad(StatusType::puts_buffer_overflow);
        return 0;
    }
    
    if (!_CheckSize(size)) return 0;
    if (!status.IsStandardOutput()) m_size += size;

    int ret_puts = test::out::FPuts<wchar_t>(*m_wchar_tmp, m_file);

    if (ret_puts < 0)
    {
        status.Bad(StatusType::puts_output_failed);
        return 0;
    }
    return size;
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Puts(const wchar_t * cstr)
{
    const auto size = test::cstr::Length<wchar_t>::Value(cstr, MaximumBuffer);
    return Puts(cstr, size);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<std::size_t S>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Puts(const wchar_t(&cstr)[S])
{
    return Puts(cstr, S - 1);
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::Puts(const test::CString<wchar_t>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::SizeType 
File<MinimumBuffer, MaximumBuffer>::
    Puts(const test::CString<const wchar_t>& cstr)
{
    return Puts(*cstr, cstr.Size());
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
test::CString<TChar> File<MinimumBuffer, MaximumBuffer>::Buffer() const
{
    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);

    auto guard = pthis->BaseType::BufferGuard();
    if (!guard) return test::CString<char>("", 0);

    return {m_char_tmp};
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
test::CString<TChar>  File<MinimumBuffer, MaximumBuffer>::Buffer() const
{
    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);

    auto guard = pthis->BaseType::BufferGuard();
    if (!guard) return test::CString<wchar_t>(L"", 0);

    return {m_wchar_tmp};
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File< MinimumBuffer, MaximumBuffer>::IsGood() const
{
    const auto& status = GetStatus();

    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return false;
    
    if (status.IsBad()) return false;

    pthis->_Initialize();

    return status.IsGood();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::IsBad() const
{
    const auto& status = GetStatus();

    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return true;

    if (status.IsBad()) return true;
    
    pthis->_Initialize();
    return status.IsBad();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
typename File<MinimumBuffer, MaximumBuffer>::StatusValueType 
File<MinimumBuffer, MaximumBuffer>::GetBadCode() const
{
    const auto& status = GetStatus();

    auto* pthis = const_cast<File<MinimumBuffer, MaximumBuffer>*>(this);
    if (!pthis) return status.GetBadCode();

    if (status.IsBad()) return status.GetBadCode();
    
    pthis->_Initialize();
    return status.GetBadCode();
}

template<std::size_t MinimumBuffer, std::size_t MaximumBuffer>
bool File<MinimumBuffer, MaximumBuffer>::IsStandard() const
{
    return GetStatus().IsStandardOutput();
}

} //!out

} //!test

#endif //!TEST_OUT_FILE_H_
