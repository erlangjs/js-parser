//
// Created by Duzhong Chen on 2019/9/3.
//
#pragma once

#include <vector>
#include <iostream>
#include "../tokenizer/Token.h"
#include "ParserContext.h"
#include "ParserCommon.h"
#include "ErrorMessage.h"
#include "NodesSize.h"

#define ASSERT_NOT_NULL(EXPR, MSG) if ((EXPR) == nullptr) { \
        LogError(std::string(#EXPR) + " should not be nullptr " + MSG); \
        return false; \
    }

namespace parser {

    class JSXParser;
    class TypeScriptParser;

    class Parser final: private ParserCommon {
    public:
        friend class JSXParser;
        friend class TypeScriptParser;

        typedef std::function<void (const Sp<ImportDeclaration>&)> ImportDeclarationCreatedCallback;

        Parser(std::shared_ptr<ParserContext> state):
        ParserCommon(state) {}
//            nodes_pool(node_size::max_node_size) {}

        void OnImportDeclarationCreated(ImportDeclarationCreatedCallback callback);

        template <typename T>
        Sp<T> IsolateCoverGrammar(std::function<Sp<T>()> cb) {
            auto previousIsBindingElement = ctx->is_binding_element_;
            auto previousIsAssignmentTarget = ctx->is_assignment_target_;
            auto previousFirstCoverInitializedNameError = ctx->first_cover_initialized_name_error_;

            ctx->is_binding_element_ = true;
            ctx->is_assignment_target_ = true;
            ctx->first_cover_initialized_name_error_.reset();

            Sp<T> result = cb();
            if (ctx->first_cover_initialized_name_error_) {
                ThrowUnexpectedToken(Token(), "firstCoverInitializedNameError");
                return nullptr;
            }

            ctx->is_binding_element_ = previousIsBindingElement;
            ctx->is_assignment_target_ = previousIsAssignmentTarget;
            ctx->first_cover_initialized_name_error_ = previousFirstCoverInitializedNameError;

            return result;
        }

        template <typename T>
        Sp<T> InheritCoverGrammar(std::function<Sp<T>()> cb) {
            auto previousIsBindingElement = ctx->is_binding_element_;
            auto previousIsAssignmentTarget = ctx->is_assignment_target_;
            auto previousFirstCoverInitializedNameError = ctx->first_cover_initialized_name_error_;

            ctx->is_binding_element_ = true;
            ctx->is_assignment_target_ = true;
            ctx->first_cover_initialized_name_error_.reset();

            Sp<T> result = cb();

            ctx->is_binding_element_ &= previousIsBindingElement;
            ctx->is_assignment_target_ &= previousIsAssignmentTarget;
            ctx->first_cover_initialized_name_error_ =
                previousFirstCoverInitializedNameError ?
                previousFirstCoverInitializedNameError : ctx->first_cover_initialized_name_error_;

            return result;
        }

        Sp<Expression> ParsePrimaryExpression();

        Sp<SpreadElement> ParseSpreadElement();

        Sp<BlockStatement> ParsePropertyMethod(FormalParameterOptions& options);

        Sp<FunctionExpression> ParsePropertyMethodFunction();

        Sp<FunctionExpression> ParsePropertyMethodAsyncFunction();

        Sp<Property> ParseObjectProperty(bool& has_proto);

        Sp<SyntaxNode> ParseObjectPropertyKey();

        Sp<Expression> ParseObjectInitializer();

        Sp<TemplateElement> ParseTemplateHead();

        Sp<TemplateElement> ParseTemplateElement();

        Sp<TemplateLiteral> ParseTemplateLiteral();

        Sp<Pattern> ReinterpretExpressionAsPattern(const Sp<SyntaxNode>& expr);

        std::optional<FormalParameterOptions> ReinterpretAsCoverFormalsList(const Sp<SyntaxNode>& ptr);

        void CheckPatternParam(FormalParameterOptions& options, const Sp<SyntaxNode>& param);

        Sp<Expression> ParseGroupExpression();

        std::vector<Sp<SyntaxNode>> ParseArguments();

        Sp<Identifier> ParseIdentifierName();

        Sp<Expression> ParseNewExpression();

        Sp<SyntaxNode> ParseAsyncArgument();

        std::vector<Sp<SyntaxNode>> ParseAsyncArguments();

        Sp<Import> ParseImportCall();

        Sp<Expression> ParseLeftHandSideExpressionAllowCall();

        Sp<Super> ParseSuper();

        Sp<Expression> ParseLeftHandSideExpression();

        Sp<Expression> ParseUpdateExpression();

        Sp<AwaitExpression> ParseAwaitExpression();

        Sp<Expression> ParseUnaryExpression();

        Sp<Expression> ParseExponentiationExpression();

        Sp<Expression> ParseBinaryExpression();

        Sp<Expression> ParseConditionalExpression();

        Sp<Expression>
        ParseAssignmentExpression();

        Sp<Statement> ParseStatementListItem();

        Sp<BlockStatement> ParseBlock();

        Sp<VariableDeclarator> ParseLexicalBinding(VarKind kind, bool &in_for);

        std::vector<Sp<VariableDeclarator>> ParseBindingList(VarKind kind, bool& in_for);

        bool IsLexicalDeclaration();

        Sp<Declaration> ParseLexicalDeclaration(bool& in_for);

        Sp<RestElement> ParseBindingRestElement(std::vector<Token> &params, VarKind kind);

        Sp<ArrayPattern> ParseArrayPattern(std::vector<Token> &params, VarKind kind);

        Sp<Property> ParsePropertyPattern(std::vector<Token> &params, VarKind kind);

        Sp<RestElement> ParseRestProperty(std::vector<Token> &params, VarKind kind);

        Sp<ObjectPattern> ParseObjectPattern(std::vector<Token> &params, VarKind kind);

        Sp<Expression> ParseArrayInitializer();

        FormalParameterOptions ParseFormalParameters(std::optional<Token> first_restricted = std::nullopt);
        void ParseFormalParameter(FormalParameterOptions& option);
        void ValidateParam(FormalParameterOptions& option, const Token& param, const UString& name);
        bool IsStartOfExpression();

        Sp<RestElement> ParseRestElement(std::vector<Token>& params);

        Sp<SyntaxNode> ParsePattern(std::vector<Token>& params, VarKind kind = VarKind::Invalid);

        Sp<SyntaxNode> ParsePatternWithDefault(std::vector<Token> &params, VarKind kind);

        Sp<Identifier> ParseVariableIdentifier(VarKind kind);

        Sp<VariableDeclarator> ParseVariableDeclaration(bool in_for);

        std::vector<Sp<VariableDeclarator>> ParseVariableDeclarationList(bool in_for);

        Sp<VariableDeclaration> ParseVariableStatement();

        Sp<EmptyStatement> ParseEmptyStatement();

        Sp<ExpressionStatement> ParseExpressionStatement();

        Sp<Expression> ParseExpression();

        Sp<Statement> ParseIfClause();

        Sp<IfStatement> ParseIfStatement();

        Sp<DoWhileStatement> ParseDoWhileStatement();

        Sp<WhileStatement> ParseWhileStatement();

        Sp<Statement> ParseForStatement();

        Sp<ContinueStatement> ParseContinueStatement();

        Sp<BreakStatement> ParseBreakStatement();

        Sp<ReturnStatement> ParseReturnStatement();

        Sp<WithStatement> ParseWithStatement();

        Sp<SwitchCase> ParseSwitchCase();

        Sp<SwitchStatement> ParseSwitchStatement();

        Sp<Statement> ParseLabelledStatement();

        Sp<ThrowStatement> ParseThrowStatement();

        Sp<CatchClause> ParseCatchClause();

        Sp<BlockStatement> ParseFinallyClause();

        Sp<TryStatement> ParseTryStatement();

        Sp<DebuggerStatement> ParseDebuggerStatement();

        Sp<Statement> ParseStatement();

        Sp<BlockStatement> ParseFunctionSourceElements();

        Sp<FunctionDeclaration> ParseFunctionDeclaration(bool identifier_is_optional);

        Sp<FunctionExpression> ParseFunctionExpression();

        Sp<Statement> ParseDirective();

        std::vector<Sp<SyntaxNode>> ParseDirectivePrologues();

        Sp<FunctionExpression> ParseGetterMethod();

        Sp<FunctionExpression> ParseSetterMethod();

        Sp<FunctionExpression> ParseGeneratorMethod();

        Sp<YieldExpression> ParseYieldExpression();

        bool QualifiedPropertyName(const Token& token);

        Sp<MethodDefinition> ParseClassElement(bool& has_ctor);

        std::vector<Sp<MethodDefinition>> ParseClassElementList();

        bool IsPropertyKey(const Sp<SyntaxNode>& key, const UString& name);

        Sp<ClassBody> ParseClassBody();

        Sp<ClassDeclaration> ParseClassDeclaration(bool identifier_is_optional);

        Sp<ClassExpression> ParseClassExpression();

        Sp<Module> ParseModule();

        Sp<Script> ParseScript();

        Sp<Literal> ParseModuleSpecifier();

        Sp<ImportSpecifier> ParseImportSpecifier();

        std::vector<Sp<SyntaxNode>> ParseNamedImports();

        Sp<ImportDefaultSpecifier> ParseImportDefaultSpecifier();

        Sp<ImportNamespaceSpecifier> ParseImportNamespaceSpecifier();

        Sp<ImportDeclaration> ParseImportDeclaration();

        Sp<ExportSpecifier> ParseExportSpecifier();

        Sp<Declaration> ParseExportDeclaration();

        bool MatchImportCall();

        inline bool MatchAsyncFunction();

        inline std::vector<Sp<Comment>>& Comments() {
            return ctx->comments_;
        }

        ~Parser() = default;

    private:
        std::vector<ImportDeclarationCreatedCallback> import_decl_handlers_;

    };

    inline bool Parser::MatchAsyncFunction() {
        bool match = MatchContextualKeyword(u"async");
        if (match) {
            auto state = ctx->scanner_->SaveState();
            std::vector<Sp<Comment>> comments;
            ctx->scanner_->ScanComments(comments);
            Token next = ctx->scanner_->Lex();
            ctx->scanner_->RestoreState(state);

            match = (state.line_number_ == next.line_number_) && IsKeywordToken(next.type_) && (next.value_ == u"function");
        }

        return match;
    }

}
