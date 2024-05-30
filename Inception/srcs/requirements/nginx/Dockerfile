FROM alpine:3.19

RUN apk update && apk --no-cache add nginx



EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]