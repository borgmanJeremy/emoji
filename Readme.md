## Todo Before 1.0
- [ ] Add category filters to bottom of widget
- [ ] Add skin tone selector
- [ ] Figure out how to package and reference the svg's properly

## Notes
Handy commands to filter json:

Print all emoji groups:
```
cat index.json | jq '.[]| {group: .group}' | sort | uniq
```