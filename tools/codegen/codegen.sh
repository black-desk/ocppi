#!/bin/bash

set -e
set -o pipefail

GIT=${GIT:="git"}

repoRoot="$("$GIT" rev-parse --show-toplevel)"
cd "$repoRoot"/tools/codegen || exit 255

npm install .

npx quicktype "$repoRoot/runtime-spec" \
	--lang c++ \
	--namespace ocppi::runtime::config \
	--code-format with-struct \
	--wstring use-wstring \
	--source-style multi-source \
	--include-location global-include \
	--type-style pascal-case-upper-acronyms \
	--member-style camel-case-upper-acronyms \
	--enumerator-style pascal-case-upper-acronyms \
	--no-boost \
	--hide-null-optional | {

	filename="/dev/null"

	while read -r line; do
		if [[ $line != //*.hpp ]]; then
			echo "$line" >>"$filename"
			continue
		fi

		filename="$repoRoot/include/ocppi/runtime/config/${line#\/\/ }"
		echo "generating $filename"
		mkdir -p $(dirname "$filename")
		{
			echo "// Thish file is generated by quicktype,"
			echo "// check /tools/codegen for further information."
			echo "// DO NOT EDIT IT."
		} >"$filename"
	done
}

find "$repoRoot/include/ocppi/runtime/config" -name *.hpp -exec clang-format -i \{\} \;
