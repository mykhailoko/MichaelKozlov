class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << std::endl;
    }
};

class StringPrintStrategy : public PrintStrategy {
    std::string buffer;
    int docNumber;

public:
    StringPrintStrategy() : docNumber(1) {}

    void print(const Document& document) override {
        buffer += "--- doc " + std::to_string(docNumber++) + " ---\n";
        buffer += document.get() + "\n";
    }

    std::string getPrintedDocuments() const {
        return buffer;
    }
};

class MockPrintStrategy : public PrintStrategy {
    int printedDocumentsCount;

public:
    MockPrintStrategy() : printedDocumentsCount(0) {}

    void print(const Document& document) override {
        printedDocumentsCount++;
    }

    int getPrintedDocumentsCount() const {
        return printedDocumentsCount;
    }
};
